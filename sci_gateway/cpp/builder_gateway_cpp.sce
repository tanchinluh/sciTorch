// -------------------------------------------------------------------------
// sciTorch - Scilab libTorch Interface
// Copyright (C) 2019 - ByteCode - Tan Chin Luh
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// -------------------------------------------------------------------------
//
function builder_gateway_cpp()

        gw_cpp_path = get_absolute_file_path('builder_gateway_cpp.sce');

    // This line added for integrating with custom C/C++ code
    // includes_src_cpp = get_absolute_file_path("builder_gateway_cpp.sce") + "../../src/cpp";
    includes_src_cpp = '';

    // Contructing tables
    gw_cpp_files = findfiles(gw_cpp_path, '*.cpp');
    scifunctions_name = gw_cpp_files(grep(gw_cpp_files, 'sci_'));
    scifunctions_name = strsubst(scifunctions_name, 'sci_', '');
    scifunctions_name = strsubst(scifunctions_name, 'percent', '%');
    scifunctions_name = strsubst(scifunctions_name, '.cpp', '');

    cppfunctions_name = gw_cpp_files(grep(gw_cpp_files,'sci_'));
    cppfunctions_name = strsubst(cppfunctions_name, '.cpp', '');

    gw_tables = [scifunctions_name, cppfunctions_name];
    //temp_str = ['csci6' 'csci' 'csci']';  // Testing for csci6 interface
    temp_str = repmat('csci',size(scifunctions_name,1),1);
    
    gw_tables(:,3) = temp_str;
    opencv_libs = [];

    // Platform dependent setting. Split to 3 systems for easy maintenance
    if getos() == 'Darwin' then  // MacOS
        gw_cpp_files = [gw_cpp_files; "common.h"];  // Add in common header
        gw_cpp_files(gw_cpp_files == 'dllsciTorch.cpp') = [];   // Remove the file to load lib symbols in windows

        THIRDPARTY_ROOT_PATH = fullpath(gw_cpp_path + "../../thirdparty");  
        // OPENCV_INCLUDE = fullpath(THIRDPARTY_ROOT_PATH + "/opencv/MacOS/include");
        TORCH_INCLUDE = '';
        //TORCH_INCLUDE = fullpath(gw_cpp_path + "/../../thirdparty/libtorch/Linux/include");
        //TORCH2_INCLUDE = fullpath(gw_cpp_path + "/../../thirdparty/libtorch/Linux/include/torch/csrc/api/include");
        //inter_cflags = ilib_include_flag([OPENCV_INCLUDE,TORCH_INCLUDE, includes_src_cpp]);
        inter_cflags = ' -std=c++11 -stdlib=libc++ -I'; //+OPENCV_INCLUDE;
        inter_cflags =  inter_cflags;// + ' -D_GLIBCXX_USE_CXX11_ABI=0';   // This is for LIBTorch
        inter_ldflags = [];
        opencv_libs = [];
        //all_libs = [opencv_libs, "../../src/cpp/libscidlib"];
        all_libs = [];

    elseif getos() == "Linux" then  // Linux

        gw_cpp_files = [gw_cpp_files; "common.h"];
        gw_cpp_files(gw_cpp_files == 'dllsciTorch.cpp') = [];

        //        opencv_version = unix_g('pkg-config --modversion opencv');
        //        if( length(opencv_version) == 0 | ( strtod( strsubst(opencv_version, '.', '')) <= 99.9 ) )
        //            disp(gettext("OpenCV (version >= 2.4.3) is needed for compiling IPCV."));
        //        end;
        //
        //        if ( strtod( strsubst(opencv_version, '.', '')) < 111 ) then //if opencv version <1.1.1
        //            inter_cflags = "-DOPENCV_V1 ";
        //        else
        //            inter_cflags = "-DOPENCV_V2 ";
        //        end;
        //
        //        inter_cflags = inter_cflags + unix_g('pkg-config --cflags opencv');
        //
        //        OPENCV_INCLUDE_ROOT_PATH = fullpath(gw_cpp_path + "../../thirdparty/opencv/Linux/include");
        //        OPENCV_INCLUDE = fullpath(OPENCV_INCLUDE_ROOT_PATH + "/opencv");
        //        OPENCV2_INCLUDE = fullpath(OPENCV_INCLUDE_ROOT_PATH + "/opencv2");
        //        
        //        if isempty(inter_cflags)
        //            inter_cflags =  ' -I'+OPENCV_INCLUDE_ROOT_PATH + ' -I'+OPENCV_INCLUDE + ' -I'+OPENCV2_INCLUDE;
        //        else
        //            inter_cflags =  inter_cflags + ' -I'+OPENCV_INCLUDE_ROOT_PATH + ' -I'+OPENCV_INCLUDE + ' -I'+OPENCV2_INCLUDE;
        //        end
        //        // inter_ldflags = unix_g('pkg-config --libs opencv');
        //        //
        //        if (length(inter_cflags)==0) then
        //            disp("Can not find OpenCV. Compiling IPCV needs OpenCV");
        //        end
        THIRDPARTY_ROOT_PATH = fullpath(gw_cpp_path + "../../thirdparty");
        OPENCV_INCLUDE = fullpath(THIRDPARTY_ROOT_PATH + "/opencv/Linux/include");
        TORCH_INCLUDE = fullpath(THIRDPARTY_ROOT_PATH + "/libtorch/Linux/include");
        TORCH2_INCLUDE = fullpath(THIRDPARTY_ROOT_PATH + "/libtorch/Linux/include/torch/csrc/api/include");
        //TORCH_INCLUDE = fullpath(gw_cpp_path + "/../../thirdparty/libtorch/Linux/include");
        //TORCH2_INCLUDE = fullpath(gw_cpp_path + "/../../thirdparty/libtorch/Linux/include/torch/csrc/api/include");

        //inter_cflags = ilib_include_flag([OPENCV_INCLUDE,TORCH_INCLUDE, includes_src_cpp]);
        inter_cflags = ' -I'+OPENCV_INCLUDE;
        inter_cflags = inter_cflags + ' -I'+TORCH_INCLUDE;
        inter_cflags = inter_cflags + ' -I'+TORCH2_INCLUDE;
        //inter_cflags = inter_cflags + ' -D_GLIBCXX_USE_CXX11_ABI=0';   // This is for LIBTorch
        inter_ldflags = " -std=c++11";
        opencv_libs = [];

        //all_libs = [opencv_libs, "../../src/cpp/libscidlib"];
        all_libs = [];

    else // Windows
        // Include paths, including torch, opencv and IPCV path
        gw_cpp_files = [gw_cpp_files; "common.h"];
        [m,ipcv_path]=libraryinfo('ipcvlib');   // To get path for IPCV - macro path
        torch_tp_path = fullpath(gw_cpp_path + "../../thirdparty");
        
        TORCH_INCLUDE = fullpath(torch_tp_path + "/libtorch/windows/CPU/include");
        TORCH2_INCLUDE = fullpath(torch_tp_path + "/libtorch/windows/CPU/include/torch/csrc/api/include");
        OPENCV_INCLUDE = fullpath(ipcv_path + "/../thirdparty/opencv/windows/include");
        IPCV_INCLUDE = fullpath(ipcv_path + "/../sci_gateway/cpp");
        
        inter_cflags = ilib_include_flag([OPENCV_INCLUDE TORCH_INCLUDE, TORCH2_INCLUDE,IPCV_INCLUDE]); 
        inter_ldflags = " -std=c++11";        

        // Include IPCV library
        all_libs = fullpath(ipcv_path + "/../sci_gateway/cpp/gw_ipcv");

    end

    tbx_build_gateway('gw_sciTorch', ..
    gw_tables, ..
    gw_cpp_files, ..
    gw_cpp_path, ..
    all_libs, ..
    inter_ldflags, ..
    inter_cflags);

endfunction
// ====================================================================
builder_gateway_cpp();
clear builder_gateway_cpp;
// ====================================================================



















































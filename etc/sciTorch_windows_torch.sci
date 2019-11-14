function sciTorch_windows_torch(root_tlbx,TORCH_LIBS)


    TORCH_LIBS = ['c10',...
	'caffe2_detectron_ops',...
	'caffe2_module_test_dynamic',...
	'caffe2',...
	'foxi_dummy',...
	'foxi',...
    'libiomp5md',...
    'libiompstubs5md',...
	'onnxifi_dummy',...
	'onnxifi',...
	'torch'];

//	'gomp-8bba0e50',...

    if win64() then
        torchDllPath = root_tlbx + '\thirdparty\libtorch\windows\x64\lib\';
    else
       //caffeDllPath = root_tlbx + '\thirdparty\caffe\windows\x86\bin\';
       error('Windows 32-bits not supported');
    end

//    for l = 1:size(OPENCV_LIBS, '*')
//        if execstr('link(opencvDllPath + OPENCV_LIBS(l) + getdynlibext())', 'errcatch') <> 0 then
//            bDepsLoaded = %f;
//            
//            break;
//        end
//    end

    tmp = pwd();
    cd(torchDllPath);

    for l = 1:size(TORCH_LIBS, '*')
//        pause
        if execstr('link(TORCH_LIBS(l) + getdynlibext())', 'errcatch') <> 0 then
            bDepsLoaded = %f;
            disp(TORCH_LIBS(l));
            break;
        else
            disp(TORCH_LIBS(l)+' loaded');
        end
    end
    
    cd(tmp);

endfunction

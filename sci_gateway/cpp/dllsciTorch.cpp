/***********************************************************************
 * SIVP - Scilab Image and Video Processing toolbox
 * Original work Copyright (C) 2005  Shiqi Yu
 * 
 * IPCV - Scilab Image Processing and Computer Vision toolbox
 * Original work Copyright (C) 2017  Tan Chin Luh
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***********************************************************************/
#define NO_STRICT
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN 
#include "Windows.h"
/*--------------------------------------------------------------------------*/
#if _WIN64
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/c10.lib")
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/clog.lib")
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/cpuinfo.lib")
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/libprotobuf-lite.lib")
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/libprotobuf.lib")
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/libprotoc.lib")
#pragma comment(lib,"../../thirdparty/libtorch/windows/CPU/lib/torch.lib")
#pragma comment(lib,"../../../IPCV/thirdparty/opencv/windows/x64/lib/opencv_world412.lib")
#pragma comment(lib,"../../../IPCV/thirdparty/opencv/windows/x64/lib/opencv_img_hash412.lib")
#pragma comment(lib,"../../../IPCV/sci_gateway/cpp/gw_ipcv.lib")
#else
#pragma comment(lib,"../../thirdparty/opencv/windows/x86/lib/opencv_world410.lib")
#pragma comment(lib,"../../thirdparty/opencv/windows/x86/lib/opencv_img_hash410.lib")
#endif
/*--------------------------------------------------------------------------*/
int WINAPI DllMain (HINSTANCE hInstance , DWORD reason, PVOID pvReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return 1;
}
/*--------------------------------------------------------------------------*/



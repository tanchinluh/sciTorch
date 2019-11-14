/***********************************************************************
* sciTorch - Machine and Deep Learning Module for Scilab 6
* Original work Copyright (C) 2019  Tan Chin Luh
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


#include <Scierror.h>
#include <sciprint.h>
#include <api_scilab.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <torch/torch.h>
#include <torch/script.h>
#include <opencv2/opencv.hpp>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
//#include <opencv2/xfeatures2d.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>
//#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>


using namespace cv;
using namespace std;


// IPCV interface functions
int matdata2scidata(Mat &pImage, void *pMatData);
int scidata2matdata(Mat &pImage, void *pMatData);
int GetImage(int nPos, Mat& new_img, void* pvApiCtx);
int SetImage(int nPos, Mat& new_img, void* pvApiCtx);
int GetString(int nPos, char *&pstName, void* pvApiCtx);
int SetString(int nPos, char *&pstName, void* pvApiCtx);
int GetDouble(int nPos, double *&pstdata, int& iRows, int& iCols, void* pvApiCtx);
int GetDouble2(int nPos, double *&pstdata, int& iRows, int& iCols, void* pvApiCtx);
int SetDouble(int nPos, double *&pstdata, int& iRows, int& iCols, void* pvApiCtx);
string type2str(int type);
int is_binary_image(Mat& new_img);
int GetListImg(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_list_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_double_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_poly_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_boolean_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_sparse_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_bsparse_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_integer_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_string_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);
int get_pointer_info_imgvec(int _iRhs, int* _piParent, int *_piAddr, int _iItemPos, vector<Mat>& imgs, void* pvApiCtx);

extern "C" 
{
	//int sci_int_scitorch_forward(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	//int sci_int_mnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	////int sci_int_loadmnist(char * fname, void* pvApiCtx);
	//int sci_int_loadmnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	//int sci_sciTorch_init(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	//int GetImage(int nPos, scilabEnv env, scilabVar* in);
	int sci_sciTorch_init(char * fname, void* pvApiCtx);
	int sci_int_loadmnist(char * fname, void* pvApiCtx);
	int sci_int_mnist(char * fname, void* pvApiCtx);
	int sci_int_scitorch_forward(char * fname, void* pvApiCtx);
}


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

using namespace std;



extern "C" 
{
	int sci_int_scitorch_forward(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	int sci_int_mnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	//int sci_int_loadmnist(char * fname, void* pvApiCtx);
	int sci_int_loadmnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	int sci_sciTorch_init(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out);
	int GetImage(int nPos, scilabEnv env, scilabVar* in);
}


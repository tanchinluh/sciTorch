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

#include "common.h"

/***************************************************
* this function should be called when sciTorch is loaded
***************************************************/
//int sci_int_scitorch_load(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out) {
int sci_int_torch_load(char *fname, void* pvApiCtx) {
	
	SciErr sciErr;
	char *pstName = NULL;
	int nCurrFile = 0;
	int *pret = &nCurrFile;

	// Check input-output
	CheckInputArgument(pvApiCtx, 1, 1);
	CheckOutputArgument(pvApiCtx, 1, 1);

	//// Get inputs.  ToDo: Add error checking 
	GetString(1, pstName, pvApiCtx);

	try
	{
		// Check how many models already loaded, and continue after the last opened number
		for (nCurrFile = 0; nCurrFile < MAX_NET_NUM; nCurrFile++)
		{

			if ((TorchNet[nCurrFile].model.num_slots() == 0))
				break;
		}

		// It should not more than defined number of model loaded
		if (nCurrFile == MAX_NET_NUM)
		{
			Scierror(999, "%s: Too many DNN model loaded. Use dnn_unload or dnn_unloadall to close some models.\r\n", fname);
			return -1;
		}


		TorchNet[nCurrFile].model = torch::jit::load(pstName);
		TorchNet[nCurrFile].model.eval();

		//the output is the opened index
		nCurrFile += 1;
		int iRet = createScalarDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1, (double)*pret);
		AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;


		//return 0;
	}
	catch (const c10::Error& e)
	{

		sciprint("Error: %s \n", e.what());
		int iRet = createScalarDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1, -1);
		AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;
		return -1;
	}
	return 0;

}



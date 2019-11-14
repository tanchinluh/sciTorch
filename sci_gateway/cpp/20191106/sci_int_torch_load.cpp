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

	// Check input-output
	CheckInputArgument(pvApiCtx, 1, 1);
	CheckOutputArgument(pvApiCtx, 1, 1);


	torch::jit::script::Module model;

	// Get inputs.  ToDo: Add error checking 
	GetString(1, pstName, pvApiCtx);
	model = torch::jit::load(pstName);

	void* pdblData;
	pdblData = &model;
	
	sciErr = createPointer(pvApiCtx, nbInputArgument(pvApiCtx) + 1, pdblData);

	torch::jit::script::Module* model2 = (torch::jit::script::Module *) pdblData;
	sciprint("model2 : %i\n", model2->num_slots());
	sciprint("model1: %i\n", model.num_slots());
	AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;

	return 0;

}
/*--------------------------------------------------------------------------*/


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
// This part of codes is contributed by Driazati from pytorch forum
// https://discuss.pytorch.org/t/print-network-architecture-in-cpp-jit/60297/2

#include "common.h"
#include <iostream>
#include <memory>
//#include <inttypes.h>


void tabs(size_t num) {
	for (size_t i = 0; i < num; i++) {
		//std::cout << "\t";
		sciprint("\t");
	}
}

void print_modules(const torch::jit::script::Module& module, size_t level = 0) {

	sciprint("%s\n", module.name().name().c_str());
	for (const auto& module : module.get_modules()) {
		tabs(level + 1);
		print_modules(module, level + 1);
	}

	for (const auto& parameter : module.get_parameters()) {
		//std::cout << parameter.value().toTensor().sizes() << " (\n";

		tabs(level + 1);
		sciprint("%s\t", parameter.name().c_str());
		std::vector<int64_t> sz = parameter.value().toTensor().sizes().vec();
		std::vector<int64_t>::iterator it;
		sciprint("[");
		for (it = sz.begin(); it != sz.end(); it++) {
			sciprint("%lld,", *it);
		}
		sciprint("]\n");
	}
	sciprint("\n");
}

//int sci_int_torch_props(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out) {
int sci_int_torch_props(char *fname, void* pvApiCtx) {

	SciErr sciErr;
	void* pvPtr = NULL;
	int* piAddr = NULL;
	int iRows = 0;
	int iCols = 0;
	int nFile;
	double *out = NULL;

	// Check input-output
	CheckInputArgument(pvApiCtx, 1, 1);
	CheckOutputArgument(pvApiCtx, 0, 1);

	try
	{
		// Input 1 : Pointer to the DNN
		GetDouble(1, out, iRows, iCols, pvApiCtx);
		nFile = round(*out);
		nFile -= 1;

		// Forward pass
		TorchNet[nFile].model.eval();
		print_modules(TorchNet[nFile].model);

	}
	catch (const c10::Error& e)
	{

		sciprint("Error: %s \n", e.what());
		return -1;
	}

	return 0;

}
/*--------------------------------------------------------------------------*/





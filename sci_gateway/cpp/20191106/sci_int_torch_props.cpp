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
//int sci_sciTorch_init(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out) {
int sci_int_torch_props(char *fname, void* pvApiCtx) {

	SciErr sciErr;
	void* pvPtr = NULL;
	//torch::jit::script::Module* pvPtr;
	int* piAddr = NULL;
	
	//sciprint("%i\n", model->num_slots());
	// Check input-output
	CheckInputArgument(pvApiCtx, 1, 1);
	//CheckOutputArgument(pvApiCtx, 0, 1);

	////torch::jit::script::Module* model2 = (torch::jit::script::Module *) pdblData;
	////sciprint("%i\n", model2->num_slots());

	sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddr);
	if (sciErr.iErr)
	{
		printError(&sciErr, 0);
		return 0;
	}
	sciErr = getPointer(pvApiCtx, piAddr, &pvPtr);
	if (sciErr.iErr)
	{
		printError(&sciErr, 0);
		return 0;
	}

	torch::jit::script::Module *model = (torch::jit::script::Module *) pvPtr;
	torch::jit::script::Module model2 = *model;
	sciprint("%i\n", model->num_slots());

	//torch::jit::script::Module model;
	//model = (torch::jit::script::Module &) pvPtr;
	//model2.eval();
	//torch::jit::script::Module model2 = *model; 
	
	//sciprint("%i\n", model->num_slots());
	//model2.eval();
	//sciprint("%i\n", model2.num_slots());
	//(const torch::jit::script::Module &)model = *pvPtr;
	//torch::jit::script::Module* model;
	//model = pvPtr;
	//model = (const torch::jit::script::Module &)pvPtr;
	//model = (const torch::jit::script::Module &) pvPtr;
	//model = &torch::jit::script::Module::operator = pvPtr;
	//torch::jit::script::Module model2 = *model;
	//model->eval();
	//////////////////////////////////////////////////
	//cv::Mat src_image, image;
	//GetImage(2, image, pvApiCtx);

	//// Working Example for Direct Image file input
	////Mat image;
	////cv::resize(src_image, image, cv::Size(224,224), cv::INTER_CUBIC);
	//std::vector<int64_t> sizes = { 1, image.rows, image.cols,3 };

	//// Choice of different input image datatype? 
	////at::TensorOptions options(at::ScalarType::Byte);// For uint8 image
	//at::TensorOptions options(at::ScalarType::Double);// For double image

	//												  // Convert image to torch format
	//at::Tensor input = torch::from_blob(image.data, at::IntList(sizes), options);
	//input = input.permute({ 0, 3, 1, 2 }); // convert to CxHxW
	//input = input.toType(at::kFloat);
	//std::vector<torch::jit::IValue> inputs;
	//inputs.push_back(input);

	//// Forward pass
	//model.eval();
	////at::Tensor output = model.forward(inputs).toTensor();

	//// Output to Scilab = To be simplified.
	//double* pdblReal = NULL;
	//pdblReal = (double*)malloc(sizeof(double) * output.size(1));

	//// Output data to Scilab workspace
	//for (int cnt = 0; cnt < output.size(1); cnt++)
	//{
	//	*(pdblReal + cnt) = output[0][cnt].item().to<double>();
	//}

	//int dims_var[2] = { output.size(0),output.size(1) };
	//int *dims;

	//dims = dims_var;
	//sciErr = createHypermatOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1, dims, 2, pdblReal);
	//AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;

	return 0;

}
/*--------------------------------------------------------------------------*/


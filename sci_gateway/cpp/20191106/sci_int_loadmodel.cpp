#include "common.h"


//int sci_int_loadmnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out){
int sci_int_loadmodel(char* fname, void* pvApiCtx) 
{
	char *pstName = NULL;
	torch::jit::script::Module model;

	// Check input-output
	CheckInputArgument(pvApiCtx, 2, 2);
	CheckOutputArgument(pvApiCtx, 0, 1);
	
	// Get inputs.  ToDo: Add error checking 
	GetString(1, pstName, pvApiCtx);
	model = torch::jit::load(pstName);

	cv::Mat src_image, image;
	GetImage(2, image, pvApiCtx);

	// Working Example for Direct Image file input
	//Mat image;
	//cv::resize(src_image, image, cv::Size(224,224), cv::INTER_CUBIC);
	std::vector<int64_t> sizes = { 1, image.rows, image.cols,3};
	
	// Choice of different input image datatype? 
	//at::TensorOptions options(at::ScalarType::Byte);// For uint8 image
	at::TensorOptions options(at::ScalarType::Double);// For double image
	
	// Convert image to torch format
	at::Tensor input = torch::from_blob(image.data, at::IntList(sizes), options);
	input = input.permute({ 0, 3, 1, 2 }); // convert to CxHxW
	input = input.toType(at::kFloat);
	std::vector<torch::jit::IValue> inputs;
	inputs.push_back(input);

	// Forward pass
	model.eval();
	at::Tensor output = model.forward(inputs).toTensor();

	// Output to Scilab = To be simplified.
	double* pdblReal = NULL;
	pdblReal = (double*)malloc(sizeof(double) * output.size(1));

	// Output data to Scilab workspace
	for (int cnt = 0; cnt < output.size(1); cnt++)
	{
		*(pdblReal + cnt) = output[0][cnt].item().to<double>();
	}

	SciErr sciErr;
	int dims_var[2] = { output.size(0),output.size(1) };
	int *dims;

	dims = dims_var;
	sciErr = createHypermatOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1, dims, 2, pdblReal);
	AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;

	return 0;
}
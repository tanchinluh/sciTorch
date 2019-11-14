#include "common.h"
#include "lenet.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

//int sci_int_scitorch_forward(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out){
int sci_int_scitorch_forward(char *fname, void* pvApiCtx) {

	
	////////////Sci6 interface/////////
	////Net model;
	////torch::load(model, "net.pt");
	//
	////torch::jit::script::Module model;
	std::string module_path = "mnist_cpu.pt";
	model = torch::jit::load(module_path);
	//cv::Mat img;

	//wchar_t* in0 = 0;
	////char* in0 = NULL;
	////in[1] : string
	//if (scilab_isString(env, in[0]) == 0 || scilab_isScalar(env, in[0]) == 0)
	//{
	//	Scierror(999, ("%s: Wrong type for input argument #%d: A string expected.\n"), fname, 2);
	//	return STATUS_ERROR;
	//}
	//scilab_getString(env, in[0], &in0);
	//torch::jit::script::Module model;
	//std::wstring ws(in0);
	//std::string module_path(ws.begin(), ws.end());

	//model = torch::jit::load(module_path);


	////unsigned char* in1 = NULL;
	//double* in1 = NULL;	
	//int inr1 = 0;
	//int inc1 = 0;
	//int size1 = 0;
	//int i;

	//size1 = scilab_getDim2d(env, in[1], &inr1, &inc1);
	////scilab_getUnsignedInteger8Array(env, in[1], &in1);
	//scilab_getDoubleArray(env, in[1], &in1);
	//torch::Tensor input = torch::from_blob(in1, { 1, 224, 224, 3 }, torch::kDouble);
	//input = input.permute({ 0, 3, 1, 2 }); // convert to CxHxW
	////////////////////////////////


	////////////////////////For mnist
	//std::vector<torch::jit::ivalue> input;
	//std::vector<int64_t> sizes = { 1, 1, 28, 28 };
	//at::TensorOptions options(at::ScalarType::Double);
	//at::tensor input = torch::from_blob(in1, at::intlist(sizes), options);
	////////////////////////

	//////////////////////////Googlenet input file
	//cv::Mat img_float;
	//cv::Mat image = cv::imread("cat.jpg");
	//cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	//image.convertTo(img_float, CV_32FC3, 1.0f / 255.0f);
	//cv::resize(img_float, img_float, cv::Size(224, 224));
	//torch::Tensor input = torch::from_blob(img_float.data, { 1, 224, 224, 3 }, torch::kFloat);
	//input = input.permute({ 0, 3, 1, 2 });
	//input[0][0] = input[0][0].sub_(0.485).div_(0.229);
	//input[0][1] = input[0][1].sub_(0.456).div_(0.224);
	//input[0][2] = input[0][2].sub_(0.406).div_(0.225);
	//torch::Tensor input = torch::from_blob(in1, { 1, 224, 224, 3 }, torch::kDouble);
	//input = input.permute({ 0, 3, 1, 2 }); // convert to CxHxW
	/////////////////////////////////////////////////




	//img_tensor = img_tensor.to(torch::kF32);
	//auto img_tensor = torch::from_blob(img_float.data, at::IntList(sizes), torch::kFloat);
	//img_tensor = img_tensor.permute({ 0, 3, 1, 2 });
	//img_tensor[0][0] = img_tensor[0][0].sub_(0.485).div_(0.229);
	//img_tensor[0][1] = img_tensor[0][1].sub_(0.456).div_(0.224);
	//img_tensor[0][2] = img_tensor[0][2].sub_(0.406).div_(0.225);


	//cv::Mat img = cv::imread("cat.jpg");
	//cv::resize(img, img, cv::Size(224, 224), cv::INTER_CUBIC);	
	//// Convert the image and label to a tensor.
	//torch::Tensor input = torch::from_blob(img.data, { 1, img.rows, img.cols, 3 }, torch::kByte);
	//input = input.permute({ 0, 3, 1, 2 }); // convert to CxHxW
	//input = input.to(torch::kF32);

	

	input = input.toType(at::kFloat);
	std::vector<torch::jit::IValue> inputs;
	inputs.push_back(input);
	model.eval();
	at::Tensor output = model.forward(inputs).toTensor();
	
	//at::Tensor output = model.forward(input);
	////at::Tensor result = module->forward({ tensor_image }).toTensor();
	for (int cnt = 0; cnt < 10; cnt++)
	{
		sciprint("%f\n", output[0][cnt].item().to<double>());
	}
	sciprint("%i\n%i\n%i\n", output.size(0), output.size(1));

	//int outr1 = output.size(0);
	//int outc1 = output.size(1);
	//double* out1 = NULL;

	//out[0] = scilab_createDoubleMatrix2d(env, outr1, outc1, 0);
	//scilab_getDoubleArray(env, out[0], &out1);

	//for (i = 0; i < output.size(1); ++i)
	//{
	//	out1[i] = output[0][i].item().to<double>();
	//}


	return 0;
}



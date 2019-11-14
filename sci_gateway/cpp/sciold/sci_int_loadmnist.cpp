#include "common.h"
#include "lenet.h"

//int sci_int_loadmnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out){
int sci_int_loadmnist(char * fname, void* pvApiCtx) {


	//GetImage(0,env, in);

	////unsigned char* in1 = NULL;
	//double* in1 = NULL;
	//double* out1 = NULL;
	//int inr1 = 0;
	//int inc1 = 0;
	//int size1 = 0;
	//int i;

	//Net model;
	//torch::load(model, "net.pt");

	//size1 = scilab_getDim2d(env, in[0], &inr1, &inc1);
	////scilab_getUnsignedInteger8Array(env, in[0], &in1);
	//scilab_getDoubleArray(env, in[0], &in1);
	//

	//std::vector<int64_t> sizes = { 1, 1, 28, 28 };
	//at::TensorOptions options(at::ScalarType::Double);

	//at::Tensor input = torch::from_blob(in1, at::IntList(sizes), options);
	//input = input.toType(at::kFloat);
	//model->eval();
	//at::Tensor output = model->forward(input);
	//////at::Tensor result = module->forward({ tensor_image }).toTensor();
	//for (int cnt = 0; cnt < 10; cnt++)
	//{
	//	sciprint("%f\n", output[0][cnt].item().to<double>());
	//}


	////out[0] = scilab_createDoubleMatrix2d(env, inr1, inc1, 0);
	////scilab_getDoubleArray(env, out[0], &out1);

	////for (i = 0; i < size1; ++i)
	////{
	////	out1[i] = in1[i];
	////}
	////scilab_getDoubleArray(env, in[0], &in1);
	////out[0] = scilab_createDoubleMatrix2d(env, row1, col1, 0);
	////scilab_getDoubleArray(env, out[0], &out1);
	//
	//	////////////////////////////////////////////////////////////////////////
	//	//// Working Example for Direct Image file input
	//	//cv::Mat image, src_image;
	//	//src_image = cv::imread("image1.jpg", 0);
	//	//cv::resize(src_image, image, cv::Size(28,28), 0, 0, cv::INTER_LINEAR);
	//	//std::vector<int64_t> sizes = { 1, 1, image.rows, image.cols };
	//	//at::TensorOptions options(at::ScalarType::Byte);
	//	//at::Tensor input = torch::from_blob(image.data, at::IntList(sizes), options);
	//	//input = input.toType(at::kFloat);

	//	//model->eval();
	//	//at::Tensor output = model->forward(input);
	//	//////at::Tensor result = module->forward({ tensor_image }).toTensor();
	//	//for (int cnt = 0; cnt < 10; cnt++)
	//	//{
	//	//	sciprint("%f\n", output[0][cnt].item().to<double>());
	//	//}
	//	////////////////////////////////////////////////////////////////////////



	return 0;
}



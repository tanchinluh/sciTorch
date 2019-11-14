#include "common.h"
#include "lenet.h"

//int sci_int_loadmnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out){
int sci_int_loadmnist(char* fname, void* pvApiCtx) 
{
	char *pstName = NULL;

	CheckInputArgument(pvApiCtx, 2, 2);
	CheckOutputArgument(pvApiCtx, 0, 1);
	
	Net model;
	
	GetString(1, pstName, pvApiCtx);
	//torch::load(model, "net.pt");
	torch::load(model, pstName);

	Mat src_image;
	GetImage(2, src_image, pvApiCtx);

	////////////////////////////////////////////////////////////////////
	// Working Example for Direct Image file input
	cv::Mat image;
	//src_image = cv::imread("image1.jpg", 0);
	cv::resize(src_image, image, cv::Size(28,28), 0, 0, cv::INTER_LINEAR);
	std::vector<int64_t> sizes = { 1, 1, image.rows, image.cols };
	at::TensorOptions options(at::ScalarType::Byte);
	at::Tensor input = torch::from_blob(image.data, at::IntList(sizes), options);
	input = input.toType(at::kFloat);

	model->eval();
	at::Tensor output = model->forward(input);
	////at::Tensor result = module->forward({ tensor_image }).toTensor();
	for (int cnt = 0; cnt < 10; cnt++)
	{
		sciprint("%f\n", output[0][cnt].item().to<double>());
	}
	////////////////////////////////////////////////////////////////////



	return 0;
}




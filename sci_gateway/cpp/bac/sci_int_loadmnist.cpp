
#include <torch/torch.h> 
#include <torch/script.h>
#include <opencv2/opencv.hpp>
#include "common.h"
#include "lenet.h"

//struct NetImpl : torch::nn::Module {};
//TORCH_MODULE(Net);




int sci_int_loadmnist(char * fname, void* pvApiCtx) {


	Net model;
	torch::load(model, "net.pt");

	//auto in = torch::rand({ 1, 1, 28, 28 });
	//auto out = model->forward(in);
	//torch::jit::script::Module model = torch::jit::load("net.pt");
	//model.eval();
	
	// Create a vector of inputs.
	//std::vector<torch::jit::IValue> inputs;
	//inputs.push_back(torch::ones({ 1, 1, 28, 28 }));

	//// Execute the model and turn its output into a tensor.
	//at::Tensor output = model.forward(inputs).toTensor();
	////std::cout << output << std::endl;

	//CheckInputArgument(pvApiCtx, 0, 1);
	//CheckOutputArgument(pvApiCtx, 0, 1);

	//string model_path = "model_cpu.pt";
	//std::shared_ptr<torch::jit::script::Module> module = torch::jit::load("model_cpu.pt");
	//module->to(at::kCUDA);
	//Net model;
	//torch::jit::load(model, "net.pt");
	//sciprint("Model %s loaded.\n", model_path);

	//try
	//{
	//	//assert(model != nullptr);


	//	model->eval();

		////////////////////////////////////////////////////////////////////////
		//// Working Example for Direct Image file input
		//cv::Mat image, src_image;
		//src_image = cv::imread("image1.jpg", 0);
		//cv::resize(src_image, image, cv::Size(28,28), 0, 0, cv::INTER_LINEAR);
		//std::vector<int64_t> sizes = { 1, 1, image.rows, image.cols };
		//at::TensorOptions options(at::ScalarType::Byte);
		//at::Tensor in = torch::from_blob(image.data, at::IntList(sizes), options);
		//in = in.toType(at::kFloat);
		//at::Tensor out = model->forward(in);
		//////at::Tensor result = module->forward({ tensor_image }).toTensor();
		//for (int cnt = 0; cnt < 10; cnt++)
		//{
		//	sciprint("%f\n", out[0][cnt].item().to<double>());
		//}
		////////////////////////////////////////////////////////////////////////

	//	//Mat mat;
	//	//GetImage(1, mat, pvApiCtx);
	//	//cv::resize(mat, mat, cv::Size(28, 28));
	//	//std::vector<cv::Mat> channels(3);
	//	//cv::split(mat, channels);

	//	//auto R = torch::from_blob(channels[0].ptr(),{ 28, 28 },torch::kUInt8);
	//	//auto G = torch::from_blob(channels[1].ptr(),{ 28, 28 },torch::kUInt8);
	//	//auto B = torch::from_blob(channels[2].ptr(),{ 28, 28 },torch::kUInt8);
	//	//auto in = torch::cat({ R, G, B }).view({ 3, 28, 28 }).to(torch::kFloat);



	//	auto out = model->forward(in);


	//	int iRows1 = 10;
	//	int iCols1 = 1;
	//	double* pdblReal1 = NULL;
	//	pdblReal1 = new double[iRows1*iCols1];
	//	//pdblReal1 = *out.double();
	//	//pdblReal1 = out.data<double>();


	//	for (int cnt = 0; cnt < iRows1; cnt++)
	//	{
	//		pdblReal1[cnt] = out[0][cnt].item().to<double>();
	//	}


	//	//out[i][j][k].item().to<double>()

	//	SetDouble(1, pdblReal1, iRows1, iCols1, pvApiCtx);
	//	// Create a vector of inputs.
	//	//std::vector<torch::jit::IValue> inputs;
	//	//sciprint("Input created.\n");
	//	//inputs.push_back(torch::ones({ 1, 1, 28, 28 }));
	//	//sciprint("Input pushed back.\n");
	//	//inputs.to(at::kCUDA);

	//	//at::Tensor output = module->forward(inputs).toTensor();
	//	//sciprint("Input forwarded.\n");


	//	//inputs.emplace_back(torch::rand({ 1, 1,  28, 28	 }));
	//	// Execute the model and turn its output into a tensor.
	//	//at::Tensor output = module->forward(inputs).toTensor();

	//	// Execute the model and turn its output into a tensor.

	//	//torch::jit::IValue result = module->forward(inputs);
	//	//at::Tensor printable = result.toTensor();

	//	//std::vector<torch::jit::IValue> inputs;
	//	//inputs.push_back(torch::ones({ 1, 1, 28, 28 }));

	//	//torch::jit::IValue result = model.forward(inputs);
	//	//at::Tensor printable = result.toTensor();
	//	//std::cout << printable << std::endl;
	//	//sciprint("Done!.");
	//	//std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';

	//}
	//catch (const std::runtime_error& e)
	//{

	//	sciprint("An exception occurred. Exception Nr. %i\n", e);
	//}



	return 0;
}




#include "common.h"
#include "lenet.h"


// Where to find the MNIST dataset.
const char* kDataRoot = "./data";
const char* kModelRoot = "./torchmodel";

// The batch size for training.
const int64_t kTrainBatchSize = 64;

// The batch size for testing.
const int64_t kTestBatchSize = 1000;

// The number of epochs to train.
const int64_t kNumberOfEpochs = 10;

// After how many batches to log a new update with the loss value.
const int64_t kLogInterval = 100;


template <typename DataLoader>
void train(
	int32_t epoch,
	Net& model,
	torch::Device device,
	DataLoader& data_loader,
	torch::optim::Optimizer& optimizer,
	size_t dataset_size) {
	model->train();
	size_t batch_idx = 0;
	float loss_f;

	sciprint("[%5ld]<<", dataset_size);
	for (auto& batch : data_loader) {
		auto data = batch.data.to(device), targets = batch.target.to(device);
		optimizer.zero_grad();
		auto output = model->forward(data);
		auto loss = torch::nll_loss(output, targets);
		AT_ASSERT(!std::isnan(loss.template item<float>()));
		loss.backward();
		optimizer.step();

		if (batch_idx++ % kLogInterval == 0) {
			//std::printf(
			//sciprint(
			//	"\rTrain Epoch: %ld [%5ld/%5ld] Loss: %.4f\n",
			//	epoch,
			//	batch_idx * batch.data.size(0),
			//	dataset_size,
			//	loss.template item<float>());
			sciprint("=");
			//epoch,
			//batch_idx * batch.data.size(0),
			//dataset_size,
			//loss.template item<float>());
		}
		loss_f = loss.template item<float>();
		//sciprint(">> [%5ld] Loss: %.4f\n", dataset_size, loss.template item<float>());
	}

	sciprint(">> Loss: %.4f\n", loss_f);
}

template <typename DataLoader>
void test(
	Net& model,
	torch::Device device,
	DataLoader& data_loader,
	size_t dataset_size) {
	torch::NoGradGuard no_grad;
	model->eval();
	double test_loss = 0;
	int32_t correct = 0;
	for (const auto& batch : data_loader) {
		auto data = batch.data.to(device), targets = batch.target.to(device);
		auto output = model->forward(data);
		test_loss += torch::nll_loss(
			output,
			targets,
			/*weight=*/{},
			Reduction::Sum)
			.template item<float>();
		auto pred = output.argmax(1);
		correct += pred.eq(targets).sum().template item<int64_t>();
	}

	test_loss /= dataset_size;
	//std::printf(
	sciprint(
		"Test set: Average loss: %.4f | Accuracy: %.3f\n",
		test_loss,
		static_cast<double>(correct) / dataset_size);
}

//auto main() -> int {
//int sci_int_mnist(char * fname, void* pvApiCtx) {
int sci_int_mnist(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out) {

	torch::manual_seed(1);

	torch::DeviceType device_type;
	if (torch::cuda::is_available()) {
		sciprint("CUDA available! Training on GPU.\n");
		device_type = torch::kCUDA;
	}
	else {
		sciprint("Training on CPU..\n");
		device_type = torch::kCPU;
	}
	//device_type = torch::kCPU;
	torch::Device device(device_type);
	Net model;
	model->to(device);
	auto train_dataset = torch::data::datasets::MNIST(kDataRoot)
		.map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
		.map(torch::data::transforms::Stack<>());
	const size_t train_dataset_size = train_dataset.size().value();

	auto train_loader =
		torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
			std::move(train_dataset), kTrainBatchSize);
	auto test_dataset = torch::data::datasets::MNIST(
		kDataRoot, torch::data::datasets::MNIST::Mode::kTest)
		.map(torch::data::transforms::Normalize<>(0.1307, 0.3081))
		.map(torch::data::transforms::Stack<>());
	const size_t test_dataset_size = test_dataset.size().value();
	auto test_loader =
		torch::data::make_data_loader(std::move(test_dataset), kTestBatchSize);
	torch::optim::SGD optimizer(
		model->parameters(), torch::optim::SGDOptions(0.01).momentum(0.5));
	for (size_t epoch = 1; epoch <= kNumberOfEpochs; ++epoch) {
		sciprint("Train Epoch: %i\n", epoch);
		train(epoch, model, device, *train_loader, optimizer, train_dataset_size);
		test(model, device, *test_loader, test_dataset_size);

	}
	//torch::save(model, kModelRoot);
	//string model_path = "model_cpu.pt";
	//torch::serialize::OutputArchive output_archive;
	//model.save(output_archive);
	//output_archive.save_to(model_path);

	//torch::save(model, "model_cpu.pt");

	torch::serialize::OutputArchive output_archive;
	model->save(output_archive);
	output_archive.save_to("net.pt");

	//torch::serialize::OutputArchive model;
	//torch::save(model, "model_cpu.pt");

	//torch::serialize::OutputArchive output_archive;
	//model.save(output_archive);
	//output_archive.save_state_dict(model_path);

	//	model->save_state_dict(model_path);
	//torch.save(model.state_dict(), model_path);

	//example = torch.rand(1, 1, 28, 28)
	//traced_script_module = torch.jit.trace(model, example)
	//traced_script_module.save("model.pt")

	//std::vector<torch::jit::IValue> inputs;
	//inputs.push_back(torch::ones({1, 1, 28, 28}));

	// Execute the model and turn its output into a tensor.
	//at::Tensor output = module->forward(inputs).toTensor();

	//std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';
	//torch::save(model, "net.pt");
	return 0;
}


//int sci_int_mnist(char * fname,  void* pvApiCtx)
//{

//	return 0;
//}


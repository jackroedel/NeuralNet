#include "Variables.h"

namespace Variables
{
	unsigned int InputCount = 0;
	unsigned int OutputCount = 0;
	unsigned int HiddenLayerCount = 0;
	unsigned int NeuronCount = 0;
	unsigned int InputNum = 0;
	std::vector<float> InWeights = { 0 };
	std::vector<float> OutWeights = { 0 };
	std::vector<std::vector<float>> HiddenWeights = { {0}, {0} };
	std::vector<std::vector<float>> SampleDatIn = { {0}, {0} };
	std::vector<std::vector<float>> SampleDatOut = { {0}, {0} };
	std::vector<float> Bias = { 0 };
	std::vector<std::vector<float>> BiasWeight = { {0}, {0} };
	std::vector<std::vector<float>> HiddenVal = { {0}, {0} };
	std::vector<float> OutputVal = { 0 };
	std::vector<float> OutError = { 0 };
	std::vector<std::vector<float>> Values;
}
#pragma once
#include <vector>

namespace Variables
{
	extern unsigned int InputCount = 0;
	extern unsigned int OutputCount = 0;
	extern unsigned int HiddenLayerCount = 0;
	extern unsigned int NeuronCount = 0;
	extern unsigned int InputNum = 0;
	extern std::vector<float> InWeights = { 0 };
	extern std::vector<float> OutWeights = { 0 };
	extern std::vector<std::vector<float>> HiddenWeights = { {0}, {0} };
	extern std::vector<std::vector<float>> SampleDatIn = { {0}, {0} };
	extern std::vector<std::vector<float>> SampleDatOut = { {0}, {0} };
	extern std::vector<float> Bias = { 0 };
	extern std::vector<std::vector<float>> BiasWeight = { {0}, {0} };
	extern std::vector<std::vector<float>> HiddenVal = { {0}, {0} };
	extern std::vector<float> OutputVal = { 0 };
	extern std::vector<float> OutError = { 0 };

}
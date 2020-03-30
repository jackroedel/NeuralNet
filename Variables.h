#pragma once
#include <vector>

namespace Variables
{
	extern unsigned int InputCount;
	extern unsigned int OutputCount;
	extern unsigned int HiddenLayerCount;
	extern unsigned int NeuronCount;
	extern unsigned int InputNum;
	extern std::vector<float> InWeights;
	extern std::vector<float> OutWeights;
	extern std::vector<std::vector<float>> HiddenWeights;
	extern std::vector<std::vector<float>> SampleDatIn;
	extern std::vector<std::vector<float>> SampleDatOut;
	extern std::vector<float> Bias;
	extern std::vector<std::vector<float>> BiasWeight;
	extern std::vector<std::vector<float>> HiddenVal;
	extern std::vector<float> OutputVal;
	extern std::vector<float> OutError;
	extern std::vector<std::vector<float>> Values;
}
#ifndef SCAFFOLD_H
#include <vector>
#include <string>

namespace Scaffold
{
	unsigned int InputCount;
	unsigned int OutputCount;
	unsigned int HiddenLayerCount;
	unsigned int NeuronCount;
	unsigned int InputNum;
	std::vector<float> InWeights;
	std::vector<float> OutWeights;
	std::vector<std::vector<float>> HiddenWeights;
	std::vector<std::vector<float>> SampleDatIn;
	std::vector<std::vector<float>> SampleDatOut;
	std::vector<float> Bias;
	std::vector<std::vector<float>> BiasWeight;
	std::vector<std::vector<float>> HiddenVal;
	std::vector<float> OutputVal;
	std::vector<float> OutError;
	void InitNet();
    void Input(std::string txt);
    float RandWeight();
}
#endif // !SCAFFOLD_H
#include <vector>
#include "Functions.h"
#include "Scaffold.h"

void FeedForward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer, int GenNum)
{
    float sum;

    //First hidden layer
    for (int i = 0; i < Scaffold::NeuronCount; i++)
    {
        for (int m = 0; m < Scaffold::InputCount; m++)
        {
            Scaffold::HiddenVal[0][i] += Scaffold::SampleDatIn[GenNum][m] * InputLayer[(m * Scaffold::NeuronCount) + i];
        }
        Scaffold::HiddenVal[0][i] = Functions::ReLUFunc(Scaffold::HiddenVal[0][i] + (Scaffold::Bias[0] * Scaffold::BiasWeight[0][i]));
    }

    //All hidden layers
    for (int i = 1; i < Scaffold::HiddenLayerCount; i++)
    {
        for (int m = 0; m < Scaffold::NeuronCount; m++)
        {
            for (int j = 0; j < Scaffold::NeuronCount; j++) //For the previous neuron layer
            {
                Scaffold::HiddenVal[i][m] += (Scaffold::HiddenVal[i - 1][j] * HiddenLayer[i - 1][(j * Scaffold::NeuronCount) + m]);
            }
            Scaffold::HiddenVal[i][m] = Functions::ReLUFunc(Scaffold::HiddenVal[i][m] + (Scaffold::Bias[i] * Scaffold::BiasWeight[i][m]));
        }
    }

    //Output Weights
    for (int i = 0; i < Scaffold::OutputCount; i++)
    {
        for (int m = 0; m < Scaffold::NeuronCount; m++)
        {
            Scaffold::OutputVal[i] = (Scaffold::HiddenVal[Scaffold::HiddenLayerCount - 1][m] * OutputLayer[(m * Scaffold::NeuronCount) + i]);
        }
        Scaffold::OutputVal[i] = Functions::SigmoidFunc(Scaffold::OutputVal[i] + Scaffold::Bias[Scaffold::HiddenLayerCount + 1] * Scaffold::BiasWeight[Scaffold::HiddenLayerCount + 1][i]);
    }
}

void FeedBackward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer, std::vector<std::vector<float>>, int GenNum)
{
    for (int i = 0; i < Scaffold::OutputCount; i++)
    {
        Scaffold::OutError[i] = Functions::MSqrE(Scaffold::OutputVal[i], Scaffold::SampleDatOut[GenNum][i]);
    }
    for (int i = 0; i < Scaffold::OutWeights.size(); i++)
    {
        Scaffold::OutWeights[i] = (Scaffold::OutWeights[i])
    }
}
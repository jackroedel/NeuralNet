#include <vector>
#include "Propogation.h"
#include "Functions.h"
#include "Scaffold.h"
#include "Variables.h"

using namespace Propogation;

void FeedForward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer, int GenNum)
{

    //First hidden layer
    for (int i = 0; i < Variables::NeuronCount; i++)
    {
        for (int m = 0; m < Variables::InputCount; m++)
        {
            Variables::HiddenVal[0][i] += Variables::SampleDatIn[GenNum][m] * InputLayer[(m * Variables::NeuronCount) + i];
        }
        Variables::HiddenVal[0][i] = Functions::ReLUFunc(Variables::HiddenVal[0][i] + (Variables::Bias[0] * Variables::BiasWeight[0][i]));
    }

    //All hidden layers
    for (int i = 1; i < Variables::HiddenLayerCount; i++)
    {
        for (int m = 0; m < Variables::NeuronCount; m++)
        {
            for (int j = 0; j < Variables::NeuronCount; j++) //For the previous neuron layer
            {
                Variables::HiddenVal[i][m] += (Variables::HiddenVal[i - 1][j] * HiddenLayer[i - 1][(j * Variables::NeuronCount) + m]);
            }
            Variables::HiddenVal[i][m] = Functions::ReLUFunc(Variables::HiddenVal[i][m] + (Variables::Bias[i] * Variables::BiasWeight[i][m]));
        }
    }

    //Output Weights
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        for (int m = 0; m < Variables::NeuronCount; m++)
        {
            Variables::OutputVal[i] = (Variables::HiddenVal[Variables::HiddenLayerCount - 1][m] * OutputLayer[(m * Variables::NeuronCount) + i]);
        }
        Variables::OutputVal[i] = Functions::SigmoidFunc(Variables::OutputVal[i] + Variables::Bias[Variables::HiddenLayerCount + 1] * Variables::BiasWeight[Variables::HiddenLayerCount + 1][i]);
    }
}

void FeedBackward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer, std::vector<std::vector<float>>, int GenNum)
{

    float Average;
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        Variables::OutError[i] = Functions::MSqrE(Variables::OutputVal[i], Variables::SampleDatOut[GenNum][i]);
        for (int i = 0; i < Variables::OutError.size(); i++)
        {
            Average += Variables::OutError[i];
        }
        Average = Average / Variables::OutError.size();
    }
    for (int i = 0; i < Variables::OutWeights.size(); i++)
    {
        Variables::OutWeights[i] = (Variables::SampleDatOut[GenNum][i * Variables::OutputCount], Functions::MSqrEDeriv(Variables::OutputVal[i * Variables::OutputCount], Average) 
        * (Functions::SigmoidDeriv(Variables::OutWeights[i])) * Variables::OutWeights[i]);
    }
}
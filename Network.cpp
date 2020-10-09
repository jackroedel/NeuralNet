#pragma once
#include <vector>
#include <random>
#include "Variables.h"
#include "Functions.h"


struct LayerTemplate //Template for all following layer types
{
    virtual void Propogate()
    {
    }

    virtual void RandInit()
    {
    }
};

struct FCLayer : public LayerTemplate
{
private:
    Functions::ActivationFunction ActFunction;
    //The activation function used in this layer

    std::vector<float> CurrentValues; //This is equal to the input or the last value, after it was manipulated by weights, bias, etc.
    std::vector<float> Weights; //This is value of the weights that the CurrentValue feeds into

    int NeuronCount;
public:
    float LO; //Lower bound in random initialization
    float HI; //Upper bounds in random initialization
    FCLayer()
    {
        ActFunction = Functions::Sigmoid;
        NeuronCount = 0;
        LO = 0;
        HI = 1;
    }

    FCLayer (Functions::ActivationFunction Func, int Neurons)
    :ActFunction(Func), NeuronCount(Neurons){}

    FCLayer(Functions::ActivationFunction Func)
        :ActFunction(Func) {}

    void RandInit() //Randomly Initializes the network
    {
        for (int m = 0; m < NeuronCount; m++)
        {
            Weights.push_back(LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO))));
        }
    }

    friend class Network;
};

class Network
{
private:
    int InputNum; //The number of inputs into the network;

    std::vector<int> Inputs;
public:
    std::vector<LayerTemplate> Net;

    int size = Net.size();

    void PushBack(FCLayer Layer)
    {
        Net.push_back(Layer);
    }

    void RandInit()
    {
        for (int i = 0; i < Net.size(); i++)
        {
            Net[i].RandInit();
        }
    }
    /*
    //First hidden layer (INput Layer)
    for (int i = 0; i < ; i++)
    {
        for (int m = 0; m < Variables::InputCount; m++)
        {
            Net[0]. += Variables::SampleDatIn[GenNum][m] * InputLayer[(m * Variables::NeuronCount) + i];
        }
        Variables::Values[0][i] = Variables::HiddenVal[0][i];
        Variables::HiddenVal[0][i] = Net[](Variables::HiddenVal[0][i] + (Variables::Bias[0] * Variables::BiasWeight[0][i]));
    }
    //All hidden layers
    for (int i = 0; i < Variables::HiddenLayerCount; i++)

    {
        for (int m = 0; m < Variables::NeuronCount; m++)
        {
            for (int j = 0; j < Variables::NeuronCount; j++) //For the previous neuron layer
            {
                Variables::HiddenVal[i + 1][m] += (Variables::HiddenVal[i][j] * HiddenLayer[i][(j * Variables::NeuronCount) + m]);
            }
            Variables::Values[i][m] = Variables::HiddenVal[i + 1][m];
            Variables::HiddenVal[i][m] = SquashMid(Variables::HiddenVal[i][m] + (Variables::Bias[i] * Variables::BiasWeight[i][m]));

        }
    }
    //Output Weights
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        for (int m = 0; m < Variables::NeuronCount; m++)
        {
             Variables::OutputVal[i] += (Variables::HiddenVal[Variables::HiddenLayerCount - 1][m] * OutputLayer[(m + i) * Variables::OutputCount]);
        }
        Variables::OutputVal[i] = SquashOut(Variables::OutputVal[i] + Variables::Bias[Variables::HiddenLayerCount + 1] * Variables::BiasWeight[Variables::HiddenLayerCount - 1][i]);
    }

    

    void FeedBackward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer,
        std::vector<std::vector<float>>, int GenNum, float(*MidDeriv)(float), float(*OutDeriv)(float), float(*Error)(float, float), float(*ErrorDeriv)(float, float))
    {
        for (int i = 0; i < Variables::NeuronCount * Variables::OutputCount; i++)
        {
            Variables::OutWeights[i / Variables::NeuronCount] -= (OutDeriv(Variables::OutputVal[i % Variables::OutputCount])
                * Variables::Values[Variables::HiddenLayerCount - 1][i / Variables::NeuronCount]);
        }

    }
*/
};
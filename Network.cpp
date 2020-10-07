#pragma once
#include <vector>
#include "Variables.h"
#include "Functions.h"


struct FCLayer
{
private:
    Functions::ActivationFunction ActFunction;
    //The activation function used in this layer

public:
    int NeuronCount;

    FCLayer()
    {
        ActFunction = Functions::Sigmoid;
        NeuronCount = 0;
    }

    FCLayer (Functions::ActivationFunction Func, int Neurons)
    :ActFunction(Func), NeuronCount(Neurons){}

    FCLayer(Functions::ActivationFunction Func)
        :ActFunction(Func) {}

    float* CurrentValue = new float[NeuronCount]; //This is equal to the input or the last value, after it was manipulated by weights, bias, etc.
    float *Weights = new float[NeuronCount]; //This is value of the weights that the CurrentValue feeds into

    friend class Network;
};

class Network
{
private:
    int InputNum; //The number of inputs into the network;

    std::vector<int> Inputs;
public:
    std::vector<FCLayer> Net;

    int size = Net.size();
    void init()
    {
        for (int i = 0; i < Net.size(); i++)
        {
            for (int m = 0;  m < Net[i].NeuronCount;  m++)
            {
                Net[i].Weights[m] = 69;
            }
        }
    }
    void PushBack(FCLayer Layer)
    {
        Net.push_back(Layer);
    }

        void FeedForward(int GenNum)
        {
            for (int i = 0; i < Net.size(); i++)
            {
                for (int m = 0; m < Net[i].NeuronCount; m++)
                {

                }
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
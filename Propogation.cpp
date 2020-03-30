#include <vector>
#include "Propogation.h"
#include "Functions.h"
#include "Scaffold.h"
#include "Variables.h"

void Propogation::FeedForward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer, int GenNum, float(*SquashMid)(float), float(*SquashOut)(float))
{
    /*
    //First hidden layer (INput Layer)
    for (int i = 0; i < Variables::NeuronCount; i++)
    {
        for (int m = 0; m < Variables::InputCount; m++)
        {
           Variables::HiddenVal[0][i] += Variables::SampleDatIn[GenNum][m] * InputLayer[(m * Variables::NeuronCount) + i];
        }
        Variables::Values[0][i] = Variables::HiddenVal[0][i];
        Variables::HiddenVal[0][i] = SquashMid(Variables::HiddenVal[0][i] + (Variables::Bias[0] * Variables::BiasWeight[0][i]));
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
    }*/
    //Output Weights
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        for (int m = 0; m < Variables::NeuronCount; m++)
        {  
           Variables::OutputVal[i] += (Variables::HiddenVal[Variables::HiddenLayerCount - 1][m] * OutputLayer[(m + i) * Variables::OutputCount]);
        }
        Variables::OutputVal[i]= SquashOut(Variables::OutputVal[i] + Variables::Bias[Variables::HiddenLayerCount + 1] * Variables::BiasWeight[Variables::HiddenLayerCount - 1][i]);
    }
}

void Propogation::FeedBackward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer,
std::vector<std::vector<float>>, int GenNum, float(*MidDeriv)(float), float(*OutDeriv)(float), float(*Error)(float, float), float(*ErrorDeriv)(float, float))
{
/*
    float Average;
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        Variables::OutError[i] = Error(Variables::OutputVal[i], Variables::SampleDatOut[GenNum][i]);
        for (int i = 0; i < Variables::OutError.size(); i++)
        {
            Average += Variables::OutError[i];
        }
        Average = Average / Variables::OutputCount;
    }
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        for(int m = 0; m < Variables::NeuronCount; m++)
        {
           // Variables::OutWeights[m * Variables::OutputCount] = Variables::OutWeights[i] - (ErrorDeriv(Variables::OutError[i], 
            //Variables::SampleDatOut[GenNum][i]) * OutDeriv(Variables::HiddenLayerCount* Variables::Values[Variables::HiddenLayerCount - 1][0]);
        }
    }*/
}
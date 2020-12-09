#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <memory>
#include "Functions.h"
#include "Network.h"


FCLayer::FCLayer()
{
    ActFunction = Functions::Sigmoid;
    NeuronCount = 0;
    LO = 0;
    HI = 1;
    Dimension = 1;
}

FCLayer::FCLayer(Functions::ActivationFunction Func, int Neurons)
    :ActFunction(Func), NeuronCount(Neurons) {}

FCLayer::FCLayer(Functions::ActivationFunction Func)
    :ActFunction(Func) {}

void FCLayer::RandInit(int NextLayerParams) //Randomly Initializes the network
{
    std::cout << "fheuwioa";
    for (int m = 0; m < NeuronCount * NextLayerParams; m++)
    {
        std::cout << NeuronCount << std::endl;
        std::cout << NextLayerParams << std::endl;
        std::cout << NextLayerParams;
        Weights.push_back(LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO))));
    }
}

void FCLayer::XavierInit(Network *Net)
{
    for (int i = 0; i < NeuronCount; i++)
    {
        //Do Xavier Intialization
    }
}

int FCLayer::ParameterCount()
{
    return NeuronCount;
}


ConvLayer::ConvLayer(int ZeroPadsIn, int StrideIn, int Height, int Width, int DepthIn)
{
    FilterDimensions.first = Height;
    FilterDimensions.second = Width;
    Stride = StrideIn;
    ZeroPads = ZeroPadsIn;
    Depth = DepthIn;
    Filter.reserve(FilterDimensions.first * FilterDimensions.second);
}

void ConvLayer::Propogate(LayerTemplate* PreviousLayer)
{
    for (int i = 0; PreviousLayer->LayerInput_2D.size(); i++)
    {

    }
}

void ConvLayer::RandInit(int NextLayerParams)
{
    std::cout << "Conv Layer";
}

inline int Network::Size()
{
    return Net.size();
}

void Network::PushBack(LayerTemplate Layer)
{
    Net.push_back(&Layer);
}

void Network::RandInit()
{
    if (Net.size() == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < Net.size(); i++)
        {
            Net[i]->RandInit(1);
        }
    }
}

void Network::Propogate()
{
    for (int i = 1; i < Net.size(); i++)
    {
        if ((Net[i - 1]->LayerInput_1D.size() > 0) && (Net[i]->LayerInput_1D.size() > 0))
        {
            std::cout << "Error: Incompatable dimensions at layer " << i << std::endl;
        }
        Net[i]->Propogate(Net[i-1]);
    }
}

inline void Network::Print()
{
}
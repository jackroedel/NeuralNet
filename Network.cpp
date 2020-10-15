#pragma once
#include <vector>
#include <random>
#include "Functions.h"
#include "Network.h"


inline FCLayer::FCLayer()
{
    ActFunction = Functions::Sigmoid;
    NeuronCount = 0;
    LO = 0;
    HI = 1;
}

FCLayer::FCLayer(Functions::ActivationFunction Func, int Neurons)
    :ActFunction(Func), NeuronCount(Neurons) {}

inline FCLayer::FCLayer(Functions::ActivationFunction Func)
    :ActFunction(Func) {}

inline void FCLayer::RandInit() //Randomly Initializes the network
{
    for (int m = 0; m < NeuronCount; m++)
    {
        Weights.push_back(LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO))));
    }
}

inline int Network::Size()
{
    return Net.size();
}

void Network::PushBack(FCLayer Layer)
{
    Net.push_back(Layer);
}

inline void Network::RandInit()
{
    for (int i = 0; i < Net.size(); i++)
    {
        Net[i].RandInit();
    }
}
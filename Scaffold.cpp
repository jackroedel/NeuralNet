#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "Scaffold.h"

using namespace Scaffold;

void Scaffold::Input(std::string txt)
{
    std::ifstream InputFile(txt);
    std::cin >> InputCount;
    std::cin >> OutputCount;
    std::cin >> HiddenLayerCount;
    std::cin >> NeuronCount;
    std::cin >> InputNum;

    float Val;
    std::vector<float> TempIn;
    std::vector<float> TempOut;

    for (int i; i < InputNum; i++)
    {
        for (int j = 0; j < InputCount; j++)
        {
            std::cin >> Val;
            TempIn.push_back(Val);
        }
        SampleDatIn.push_back(TempIn);
        TempIn.clear();

        for (int m = 0; m < OutputCount; m++)
        {
            std::cin >> Val;
            TempOut.push_back(Val);
        }
        SampleDatOut.push_back(TempOut);
        TempOut.clear();
    }

    InputFile.close();
}

float Scaffold::RandWeight()
{
    return ( ((float)rand() / (float)RAND_MAX) - 0.5);
}

void Scaffold::InitNet()
{
    InWeights.resize(InputCount * NeuronCount);
    for (int i = 0; i < InWeights.size(); i++)
    {
        InWeights[i] = RandWeight();
    }

    OutWeights.resize(OutputCount * NeuronCount);
    OutError.resize(OutputCount);
    for (int i = 0; i < OutWeights.size(); i ++)
    {
        OutWeights[i] = RandWeight();
    }

    HiddenWeights.resize(HiddenLayerCount - 1, std::vector<float>(NeuronCount * NeuronCount));
    HiddenVal.assign(HiddenLayerCount, std::vector<float>(NeuronCount, 0.0));
    OutputVal.resize(OutputCount);
    for (int i = 0; i < HiddenLayerCount - 1; i ++)
    {
        for (int m = 0; m < (NeuronCount * NeuronCount); m++)
        {
            HiddenWeights[i][m] = RandWeight();
        }
    }

    Bias.resize(HiddenLayerCount + 1);
    for (int i = 0; i < Bias.size(); i ++)
    {
        Bias[i] = 1;
    }

    BiasWeight.resize(HiddenLayerCount - 1, std::vector<float>(NeuronCount));
    for (int i = 0; i < HiddenLayerCount - 1; i ++)
    {
        for (int m = 0; m < (NeuronCount); m++)
        {
            BiasWeight[i][m] = Scaffold::RandWeight();
        }
    }
}
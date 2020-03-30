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
#include "Variables.h"

void Scaffold::Input(std::string txt)
{
    std::ifstream InputFile;
    InputFile.open(txt);
    InputFile >> Variables::InputCount;
    InputFile >> Variables::OutputCount;
    InputFile >> Variables::HiddenLayerCount;
    InputFile >> Variables::NeuronCount;
    InputFile >> Variables::InputNum;
    float Val;
    std::vector<float> TempIn;
    std::vector<float> TempOut;

    for (int i = 0; i < Variables::InputNum; i++)
    {
        for (int j = 0; j < Variables::InputCount; j++)
        {
            InputFile >> Val;
            TempIn.push_back(Val);
        }
        Variables::SampleDatIn.push_back(TempIn);
        TempIn.clear();

        for (int m = 0; m < Variables::OutputCount; m++)
        {
            InputFile >> Val;
            TempOut.push_back(Val);
        }
        Variables::SampleDatOut.push_back(TempOut);
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
    
    if (Variables::HiddenLayerCount <= 0)
    {
        std::cout << "Hidden Layer Count too small, automatically corrected to one" << std::endl;
        Variables::HiddenLayerCount = 1;
    }
    Variables::InWeights.resize(Variables::InputCount * Variables::NeuronCount);
    for (int i = 0; i < Variables::InWeights.size(); i++)
    {
        Variables::InWeights[i] = Scaffold::RandWeight();
    }

    Variables::OutWeights.resize(Variables::OutputCount * Variables::NeuronCount);
    Variables::OutError.resize(Variables::OutputCount);
    for (int i = 0; i < Variables::OutWeights.size(); i ++)
    {
        Variables::OutWeights[i] = RandWeight();
    }
    
    Variables::HiddenWeights.assign(Variables::HiddenLayerCount - 1, std::vector<float>(Variables::NeuronCount * Variables::NeuronCount));
    Variables::HiddenVal.assign(Variables::HiddenLayerCount, std::vector<float>(Variables::NeuronCount, 0.0));
    Variables::OutputVal.resize(Variables::OutputCount);

    for(int i = 0; i < (Variables::HiddenLayerCount - 1); i++)
    {
        for(int m = 0; m < (Variables::NeuronCount * Variables::NeuronCount); m++)
        {
            Variables::HiddenWeights[i][m] = Scaffold::RandWeight();
        }
    }
    
    Variables::Bias.resize(Variables::HiddenLayerCount + 1);
    for (int i = 0; i < Variables::Bias.size(); i ++)
    {
        Variables::Bias[i] = 1;
    }

    Variables::BiasWeight.resize(Variables::HiddenLayerCount - 2, std::vector<float>(Variables::NeuronCount));
    for (int i = 0; i < Variables::HiddenLayerCount - 2; i ++)
    {
        for (int m = 0; m < Variables::NeuronCount; m++)
        {
            Variables::BiasWeight[i][m] = RandWeight();
        }
    }
    
    std::vector<float> Temp;
    Temp.resize(Variables::OutputCount);
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        Temp[i] = Scaffold::RandWeight();
    }
    Variables::BiasWeight.push_back(Temp);
    
}
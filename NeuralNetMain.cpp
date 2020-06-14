#include <iostream>
#include <fstream>
#include <vector>
#include "Propogation.h"
#include "Scaffold.h"
#include "Variables.h"
#include "Functions.h"

int main()
{
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);
    Scaffold::Input("Input.txt");
    Scaffold::InitNet();
    //void FeedForward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer,
    //std::vector<float> OutputLayer, int GenNum, float(*SquashMid)(float), float(*SquashOut)(float));
   Propogation::FeedForward(Variables::InWeights, Variables::HiddenWeights,
    Variables::OutWeights, 0, Functions::SigmoidFunc, Functions::SigmoidFunc);
    //Propogation::FeedBackward(Variables::InWeights, Variables::HiddenWeights, Variables::OutWeights, Functions::ReLUFunc, Functions::SigmoidFunc);
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        std::cout << Variables::OutputVal[i];
    }
    return 0;
}
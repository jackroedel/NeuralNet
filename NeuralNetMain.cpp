#include <iostream>
#include <fstream>
#include <vector>
#include "Propogation.h"
#include "Scaffold.h"
#include "Variables.h"
#include "Functions.h"

int Jack;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Scaffold::Input("Input.txt");
    Scaffold::InitNet();
    Propogation::FeedForward(Variables::InWeights, Variables::HiddenWeights, Variables::OutWeights, 0, Functions::ReLUFunc, Functions::SigmoidFunc);
    //Propogation::FeedBackward(Variables::InWeights, Variables::HiddenWeights, Variables::OutWeights, Functions::ReLUFunc, Functions::SigmoidFunc);
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        std::cout << Variables::OutputVal[i];
    }
    return 0;
}
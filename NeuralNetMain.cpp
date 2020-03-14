#include <iostream>
#include "Propogation.h"
#include "Scaffold.h"
#include "Variables.h"
int main()
{
    Scaffold::Input("Input.txt");
    Scaffold::InitNet();
   // Propogation::FeedForward(Variables::InWeights, Variables::HiddenWeights, Variables::OutWeights, 0);
    for (int i = 0; i < Variables::OutputCount; i++)
    {
        std::cout << Variables::OutputVal[i] << " ";
    }
    std::cout << "worked!";
    std::cin.get();
    return 0;
}
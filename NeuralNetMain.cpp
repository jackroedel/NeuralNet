#include <iostream>
#include <fstream>
#include <vector>
#include "Functions.h"
#include "Network.h"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    FCLayer Layer1(Functions::Tanh, 1);

    ConvLayer Layer2(1,1,1,1,1);

    Network NetOne;

    NetOne.PushBack(Layer1);
    NetOne.PushBack(Layer1);
    NetOne.PushBack(Layer2);

    //std::cout << Layer1.Weights[0];
    //NetOne.Net[0].RandInit(1);
    
    NetOne.RandInit();

    NetOne.Propogate();

    return 0;
}
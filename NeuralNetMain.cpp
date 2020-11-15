#include <iostream>
#include <fstream>
#include <vector>
#include "Functions.h"
#include "Network.h"

int main()
{
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);

    FCLayer Layer1(Functions::Tanh, 99);

    FCLayer Layer2(Functions::Sigmoid, 99);

    Network NetOne;

    NetOne.PushBack(Layer1);
    
    NetOne.RandInit();

    std::cout << Layer1.Weights[0];

    NetOne.Propogate();

    std::cout << "Hello";
    return 0;
}
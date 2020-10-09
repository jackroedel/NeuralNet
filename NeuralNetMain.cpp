#include <iostream>
#include <fstream>
#include <vector>
#include "Functions.h"
#include "Network.cpp"

int main()
{
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);

    FCLayer Layer1(Functions::Tanh, 10);

    Network NetOne;
    NetOne.PushBack(Layer1);

    return 0;
}
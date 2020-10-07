#include <iostream>
#include <fstream>
#include <vector>
#include "Network.cpp"

int main()
{
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);

    FCLayer Layer1(Functions::Linear, 10);

    Network NetOne;
    NetOne.PushBack(Layer1);

    NetOne.init();

    for (int i = 0; i < Layer1.NeuronCount; i++)
    {
        std::cout << NetOne.Net[0].Weights[i];
    }

    return 0;
}
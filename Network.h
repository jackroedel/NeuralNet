#pragma once
#include <vector>

struct LayerTemplate //Template for all following layer types
{
    virtual void Propogate()
    {
    }

    virtual void RandInit()
    {
    }
};

struct FCLayer : public LayerTemplate
{
private:
    Functions::ActivationFunction ActFunction = Functions::Sigmoid;
    //The activation function used in this layer

    std::vector<float> CurrentValues; //This is equal to the input or the last value, after it was manipulated by weights, bias, etc.
    std::vector<float> Weights; //This is value of the weights that the CurrentValue feeds into

    int NeuronCount;
public:
    float LO; //Lower bound in random initialization
    float HI; //Upper bounds in random initialization
    FCLayer();

    FCLayer(Functions::ActivationFunction Func, int Neurons);

    FCLayer(Functions::ActivationFunction Func);

    void RandInit(); //Randomly Initializes the network

    friend class Network;
};

class Network
{
private:
    int InputNum; //The number of inputs into the network;

    std::vector<int> Inputs;
public:
    std::vector<LayerTemplate> Net;

    int Size();

    void PushBack(FCLayer Layer);

    void RandInit();
};
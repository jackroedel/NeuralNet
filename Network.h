#pragma once

#include <utility>
#include <vector>

class Network;

struct LayerTemplate //Template for all following layer types
{
    virtual void Propogate(LayerTemplate *PreviousLayer)
    {
    }

    virtual void RandInit(int NextLayerParams)
    {
    }

    virtual int ParamaterCount()
    {
    }

    virtual void XavierInit(Network *Net)
    {
    }

    int Dimension;

    std::vector<float> LayerInput_1D; //This is the output of the last value,
        //i.e. after it was manipulated by weights, bias, etc. (1D)

    std::vector<std::vector<float>> LayerInput_2D;//This is the output of the last value,
        //i.e. after it was manipulated by weights, bias, etc. (2D)
};

struct FCLayer : public LayerTemplate
{
    float LO; //Lower bound in random initialization
    float HI; //Upper bounds in random initialization
    FCLayer();

    FCLayer(Functions::ActivationFunction Func, int Neurons);

    FCLayer(Functions::ActivationFunction Func);

    void RandInit(int NextLayerParams); //Randomly Initializes the network **Virtual function extended from FCLayer**

    void XavierInit(Network *Net);

    int ParameterCount();//Virtual function extended from FCLayer

    friend class Network;

    std::vector<float> Weights;

private:
    Functions::ActivationFunction ActFunction = Functions::Sigmoid;
    //The activation function used in this layer

     //This is value of the weights that the CurrentValue feeds into

    float Bias; //This is the value of the Bias
    std::vector<float> BiasWeight; //Weights that the Bias uses
    
    int NeuronCount;
};

struct ConvLayer : public LayerTemplate
{
    void Propogate(LayerTemplate* PreviousLayer);

    ConvLayer(int ZeroPadsIn, int StrideIn, int Height, int Width, int DepthIn);
private:
    int Depth;
    int Stride;
    int ZeroPads;

    std::pair <unsigned int, unsigned int> FilterDimensions;
    std::vector<float> Filter;
    std::vector<float> Output;
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

    void Propogate();

    void Print();
};
#pragma once
#include <vector>

namespace Propogation
{ 
    void FeedForward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer, int GenNum);
}
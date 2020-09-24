#pragma once
#include <vector>

namespace Propogation
{ 
    void FeedForward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer,
    std::vector<float> OutputLayer, int GenNum, float(*SquashMid)(float), float(*SquashOut)(float));

    void FeedBackward(std::vector<float> InputLayer, std::vector<std::vector<float>> HiddenLayer, std::vector<float> OutputLayer,
    std::vector<std::vector<float>>, int GenNum, float(*MidDeriv)(float), float(*OutDeriv)(float), float(*Error)(float, float), float(*ErrorDeriv)(float, float));
}
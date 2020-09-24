#pragma once
#include <utility>

namespace Functions
{
    struct ErrorFunction;

    struct ActivationFunction;
    
    float MSqrEFunc(float Expected, float Actual);

    float MSqrEDeriv(float Real, float Expected);
    
    extern ErrorFunction MeanSquaredError;
     
// ToDo: Define and write the Deriv for all these functions
    float MAbsE(float Expected, float Actual);
    float MSqrLogE(float Expected, float Actual);
    float MAbsPerE(float Expected, float Actual);
    float HingeLoss(float Expected, float Actual);
    float LogisticLoss(float Expected, float Actual);
    float NegativeLogLikelihood(float Expected, float Actual);
    float KLDivergence(float Expected, float Actual);

    float HardTanhDeriv(float x);
    float HardTanhFunc(float x);

    extern ActivationFunction HardTanh;

    float TanhDeriv(float x);
    float TanhFunc(float x);

    extern ActivationFunction Tanh;

    float LinearDeriv(float x);
    float LinearFunc(float x);

    extern ActivationFunction Linear;

    float ReLUDeriv(float x);
    float ReLUFunc(float x);

    extern ActivationFunction ReLU;

    float SigmoidDeriv(float x);
    float SigmoidFunc(float x);

    extern ActivationFunction Sigmoid;
}
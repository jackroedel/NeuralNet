#pragma once
#include <utility>

namespace Functions
{
    struct ErrorFunction
    {
        float (*Function)(float, float);
        float (*FunctionDeriv)(float, float);/*
        ErrorFunction(float (*Func)(float, float), float (*FuncDeriv)(float, float))
            :Function(Func), FunctionDeriv(FuncDeriv) {}*/
    };

    struct ActivationFunction
    {
        float (*Function)(float);
        float (*FunctionDeriv)(float);/*
        Functions::Functions::ActivationFunctionss(float (*Func)(float), float (*FuncDeriv)(float))
            :Function(Func), FunctionDeriv(FuncDeriv) {}*/
    };
    
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
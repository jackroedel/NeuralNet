#pragma once
#include <utility>

namespace Functions
{
    struct ErrorFunction
    {
        float (*Function)(float, float);
        float (*FunctionDeriv)(float, float);
        ErrorFunction(float (*Func)(float, float), float (*FuncDeriv)(float, float))
        :Function(Func), FunctionDeriv(FuncDeriv){}
    };  

    struct ActivationFunction
    {
        float (*Function)(float);
        float (*FunctionDeriv)(float);
        ActivationFunction(float (*Func)(float), float (*FuncDeriv)(float))
        :Function(Func), FunctionDeriv(FuncDeriv){}
    }; 

    float MSqrEFunc(float Expected, float Actual);
    float MSqrEDeriv(float Real, float Expected);
    
    ErrorFunction MeanSquaredError(MSqrEFunc, MSqrEDeriv);

// ToDo: Define and wirte the Deriv for all these functions
    float MAbsE(float Expected, float Actual);
    float MSqrLogE(float Expected, float Actual);
    float MAbsPerE(float Expected, float Actual);
    float HingeLoss(float Expected, float Actual);
    float LogisticLoss(float Expected, float Actual);
    float NegativeLogLikelihood(float Expected, float Actual);
    float KLDivergence(float Expected, float Actual);

    float HardTanhDeriv(float x);
    float HardTanhFunc(float x);

    ActivationFunction HardTanh(HardTanhFunc, HardTanhDeriv);

    float TanhDeriv(float x);
    float TanhFunc(float x);

    ActivationFunction Tanh(TanhFunc, TanhDeriv);

    float LinearDeriv(float x);
    float LinearFunc(float x);

    ActivationFunction Linear(LinearFunc, LinearDeriv);

    float ReLUDeriv(float x);
    float ReLUFunc(float x);

    ActivationFunction ReLU(ReLUFunc, ReLUDeriv);

    float SigmoidDeriv(float x);
    float SigmoidFunc(float x);

    ActivationFunction Sigmoid(SigmoidFunc, SigmoidDeriv);
}
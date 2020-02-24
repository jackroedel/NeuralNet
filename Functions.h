#pragma once

namespace Functions
{
    float MSqrE(float Expected, float Actual);
    float MAbsE(float Expected, float Actual);
    float MSqrLogE(float Expected, float Actual);
    float MAbsPerE(float Expected, float Actual);
    float HingeLoss(float Expected, float Actual);
    float LogisticLoss(float Expected, float Actual);
    float NegativeLogLikelihood(float Expected, float Actual);
    float KLDivergence(float Expected, float Actual);

    float HardTanhDeriv(float x);
    float HardTanhFunc(float x);

    float TanhDeriv(float x);
    float TanhFunc(float x);

    float LinearDeriv(float x);
    float LinearFunc(float x);

    float ReLUDeriv(float x);
    float ReLUFunc(float x);

    float SigmoidDeriv(float x);
    float SigmoidFunc(float x);
}
#include <cmath>
#include <algorithm>
//Loss Functions for regression
float MSqrE(float Expected, float Actual) {return ((Actual - Expected) * (Actual - Expected));}

float MAbsE(float Expected, float Actual) {return abs(Actual - Expected);}

float MSqrLogE(float Expected, float Actual)
{
    return pow((log10(Actual) - log10(Expected)), 2.0);
}

float MAbsPerE (float Expected, float Actual)
{
    return ((100 * abs(Actual - Expected)) / Actual);
}

//Loss functions for classification
float HingeLoss(float Expected, float Actual)
{
    return std::max((float)0, (1 - Actual - Expected));
}

float LogisticLoss(float Expected, float Actual)
{
    return 0.0;
}

float NegativeLogLikelihood(float Expected, float Actual)
{
    return 0.0;
}

//Loss functions for reconstruction
float KLDivergence(float Expected, float Actual)
{
    return 0.0;
}

float SigmoidFunc(float x) {return (1 / (1 + exp(-x)));}

float SigmoidDeriv(float x) {return SigmoidFunc(x) * (1 - SigmoidFunc(x));}

float ReLUFunc(float x)
{
    if (x <= 0.0) {return 0.0;}
    else {return x;};
}

float ReLUDeriv(float x)
{
    if (x <= 0.0) {return 0.0;}
    else {return 1.0;}
}

float LinearFunc(float x) {return x;}

float LinearDeriv(float x) {return 1;}

float TanhFunc(float x) {return tanh(x);}

float TanhDeriv(float x) {return (1-(tanh(x) * tanh(x)));}

float HardTanhFunc(float x)
{
    if (x < 0) {return -1.0;}
    if (x > 0) {return 1.0;}
    else {return 0;}
}

float HardTanhDeriv(float x)
{
    if (x < 1.0 && x > -1.0) {return 1;}
    else {return 0;}
}

//Geradient descent functions
fdds;lajfkl;dsajkl;fdsalk;fjdsafadsfasd
#include <vector>


class Layer
{
    float (*Function)(float) = 0;
    float (*FunctionOut)(float, float) = 0;

    Layer (float (*Func)(float))
    :Function(Func){}
    
    Layer (float (*Func)(float, float))
    :FunctionOut(Func){}
  
};

class Network
{

};

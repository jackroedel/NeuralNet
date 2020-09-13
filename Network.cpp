#include <vector>


class FCCLayer
{
    float (*Function)(float) = 0;
    float (*FunctionOut)(float, float) = 0;

    FCCLayer (float (*Func)(float))
    :Function(Func){}

    FCCLayer (float (*Func)(float, float))
    :FunctionOut(Func){}

    int NeuronCount;
};

class Network
{
    std::vector<FCCLayer> Net;

    public:
        void PushBack(FCCLayer Layer)
        {
            Net.push_back(Layer);
        }

        void Initialize();
        {
            for (int i = 0; i < Net.size(); i++)
            {
                Net[]
            }
        }

        void XavierInit()
        {

        }

};

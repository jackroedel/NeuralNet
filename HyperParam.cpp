#include <vector>
#include <iostream>

//Special Hyperparameters
template <class T>
std::vector<std::vector<T>> Transpose(std::vector<std::vector<T>> &InputVec)
{

    std::vector<std::vector<T>> ReturnVec;
    ReturnVec.resize(InputVec[0].size(), std::vector<float>(InputVec.size()));
    for (unsigned int i = 0; i < ReturnVec.size(); i++)
    {
        for (unsigned int m = 0; m < ReturnVec[0].size(); m ++)
        {
            ReturnVec[i][m] = InputVec[m][i];
        }
    }

    return ReturnVec;
}

std::vector<std::vector<float>> InVec {{2,3,4,5}, {7,8,9}};

template<class R>
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<R>> &InputVec)
{
    os << "[";
    for (int i = 0; i < InputVec.size(); i++);
    {    
        for (int m = 0; m < InputVec[0].size(); m++)
        {
            os << InputVec[i][m];
            if (m != InputVec[0].size() - 1) 
            os << ", ";
        }
        os << "/n";
    }
    return os;
}
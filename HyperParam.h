#pragma once
#include <vector>
#include <ostream>

namespace HyperParam
{
    template <class T>
    std::vector<std::vector<T>> Transpose(std::vector<std::vector<T>> &InputVec);

    template <class R>
    std::ostream& operator<<(std::ostream& os, std::vector<std::vector<R>> &InputVec);

}
#include "../include/help.hpp"
#include <iostream>
#include <string>
#include <vector>

template void help::printWithIndices<std::string>(std::vector<std::string> const &vec);

template <typename T>
void help::printWithIndices(std::vector<T> const &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << i << " : " << vec[i] << std::endl;
    }
}

bool help::number_between(int number, int lower, int upper)
{
    return number >= lower && number <= upper;
}

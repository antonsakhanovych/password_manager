#pragma once
#include <string>
#include <vector>

namespace help
{
    bool number_between(int number, int lower, int upper);

    void get_input(std::string &input, std::string const &message);
    void get_input(int &input, std::string const &message);

    template <typename T>
    void printWithIndices(std::vector<T> const &vec);
}
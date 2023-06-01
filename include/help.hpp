#pragma once
#include "password.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace help
{
    bool number_between(int number, int lower, int upper);

    template <typename T>
    void print_map(std::map<T, std::string> const &map);

    template <typename T>
    void print_vector(std::vector<T> const &vector);

}
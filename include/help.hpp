#pragma once
#include "password.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

/*! @namespace help
 *  @brief Namespace that contains helper functions
 */
namespace help
{

    /*!
     *  @fn
     *  @brief checks if given number is between lower and upper bound.
     *
     *  @param number number to check.
     *  @param lower lower bound.
     *  @param upper upper bound.
     */
    bool number_between(int number, int lower, int upper);

    /*!
     *  @fn
     *  @brief prints map to the console.
     *
     *  @tparam T type of the key.
     *  @param map map to print.
     */
    template <typename T>
    void print_map(std::map<T, std::string> const &map);

    /*!
     *  @fn
     *  @brief prints vector to the console.
     *
     *  @tparam T type of the vector.
     *  @param vector vector to print.
     */
    template <typename T>
    void print_vector(std::vector<T> const &vector);

}
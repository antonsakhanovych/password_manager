#include "../include/data.hpp"
#include <string>

void data::xorTransform(std::string &toTransform, std::string const &key)
{
    for (int i = 0; i < toTransform.size(); i++)
    {
        toTransform[i] ^= key[i % key.size()];
    }
}

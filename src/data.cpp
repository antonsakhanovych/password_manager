#include "../include/data.hpp"
#include "../include/constants.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

void data::xorTransform(std::string &toTransform, std::string const &key)
{
    for (int i = 0; i < toTransform.size(); i++)
    {
        toTransform[i] ^= key[i % key.size()];
    }
}

void data::split_record(std::string const &record, std::string &name, std::string &password, std::string &category, std::string &service, std::string &login)
{
    std::vector<std::string> splitted;
    std::stringstream ss(record);
    std::string temp;

    while (std::getline(ss, temp, constants::fdelim))
    {
        splitted.push_back(temp);
    }

    name = splitted[0];
    password = splitted[1];
    category = splitted[2];
    if (splitted.size() > 3)
    {
        service = splitted[3];
    }
    if (splitted.size() > 4)
    {
        login = splitted[4];
    }
}
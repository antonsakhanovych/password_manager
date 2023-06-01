#include "../include/password.hpp"
#include "../include/constants.hpp"
#include "../include/data.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

pass::Password::Password(std::string const &data) : data(data)
{
    int count = std::count(data.begin(), data.end(), constants::fdelim);
    if (count != 4)
    {
        throw std::invalid_argument("Record is malformed. Your might be typed your master password wrong!");
    }
    data::split_record(data, name, password, category, service, login);
}

pass::Password::~Password() {}

std::string pass::Password::get_name() const
{
    return this->name;
};

std::ostream &pass::operator<<(std::ostream &os, pass::Password const &pass)
{
    os << pass.name << " - " << pass.password << " - " << pass.category << " - " << pass.service << " - " << pass.login;
    return os;
};

bool pass::Password::is_match(std::string const &search) const
{
    return this->data.find(search) != std::string::npos;
}

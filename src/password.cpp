#include "../include/password.hpp"
#include "../include/constants.hpp"
#include "../include/data.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <filesystem>

Password::Password(std::string const &data)
{
    int count = std::count(data.begin(), data.end(), constants::fdelim);
    if (count != 4)
    {
        throw MalformedPassword();
    }
    data::split_record(data, name, password, category, service, login);
}

Password::Password(std::string const &name, std::string const &password, std::string const &category, std::string const &service, std::string const &login)
    : name(name), password(password), category(category), service(service), login(login) {}

Password::~Password() {}

std::string Password::toString(std::string delimiter) const
{
    std::string toWrite = name + delimiter +
                          password + delimiter +
                          category + delimiter +
                          service + delimiter + login;
    return toWrite;
}

std::ostream &operator<<(std::ostream &os, std::unique_ptr<Password> const &pass)
{
    os << pass->toString(" - ") << std::endl;
    return os;
};

bool Password::operator==(Password const &other) const
{
    return this->name == other.name &&
           this->password == other.password &&
           this->category == other.category &&
           this->service == other.service &&
           this->login == other.login;
}

bool Password::operator!=(Password const &other) const
{
    return !(*this == other);
}

bool Password::is_match(std::string const &search, constants::criteria criteria) const
{
    std::string const *field = this->get_field_by_criteria(criteria);
    return (*field).find(search) != std::string::npos;
}

std::string const *Password::get_field_by_criteria(constants::criteria criteria) const
{
    std::string const *field;
    switch (criteria)
    {
    case constants::criteria::Name:
        field = &this->name;
        break;
    case constants::criteria::Service:
        field = &this->service;
        break;
    case constants::criteria::Password:
        field = &this->password;
        break;
    case constants::criteria::Category:
        field = &this->category;
        break;
    case constants::criteria::Login:
        field = &this->login;
        break;
    }
    return field;
}

bool Password::compare(Password const &p1, Password const &p2, constants::criteria criteria1, constants::criteria criteria2)
{
    std::string const *field1;
    std::string const *field2;
    field1 = p1.get_field_by_criteria(criteria1);
    field2 = p2.get_field_by_criteria(criteria1);
    if (*field1 != *field2)
        return *field1 < *field2;

    field1 = p1.get_field_by_criteria(criteria2);
    field2 = p2.get_field_by_criteria(criteria2);
    return *field1 < *field2;
}

const char *MalformedPassword::what() const noexcept
{
    return "Malformed password!";
}
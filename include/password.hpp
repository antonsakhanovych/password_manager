#pragma once
#include "constants.hpp"
#include <string>
#include <filesystem>

class Password
{
private:
    std::string name;
    std::string password;
    std::string category;
    std::string service;
    std::string login;

public:
    Password(std::string const &data);
    Password(std::string const &name, std::string const &password, std::string const &category, std::string const &service, std::string const &login);
    ~Password();
    std::string toString(std::string delimiter) const;
    friend std::ostream &operator<<(std::ostream &os, std::unique_ptr<Password> const &pass);
    bool operator==(Password const &other) const;
    bool operator!=(Password const &other) const;
    bool is_match(std::string const &search, constants::criteria criteria) const;
    std::string const *get_field_by_criteria(constants::criteria criteria) const;
    static bool compare(Password const &p1, Password const &p2, constants::criteria criteria1, constants::criteria criteria2);
};

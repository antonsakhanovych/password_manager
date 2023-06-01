#include "../include/uinput.hpp"
#include "../include/constants.hpp"
#include "../include/help.hpp"
#include "../include/data.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fmt/core.h>

constants::pass_command uinput::get_password_command()
{
    help::print_map(constants::all_password_commands);
    int input;
    uinput::get_input(input, "Enter command: ", true);
    constants::pass_command command = static_cast<constants::pass_command>(input);
    return command;
}

void uinput::get_input(std::string &input, std::string const &message, bool required)
{
    std::cout << message << std::endl;
    std::getline(std::cin, input);
    if (required && input.empty())
    {
        uinput::get_input(input, message, required);
    }
}

void uinput::get_input(int &input, std::string const &message, bool required)
{
    std::cout << message << std::endl;
    std::cin >> input;
    std::cin.ignore();
    if (required && input == 0)
    {
        uinput::get_input(input, message, required);
    }
}

template constants::pass_command uinput::get_input(std::map<constants::pass_command, std::string> const &map);
template constants::criteria uinput::get_input(std::map<constants::criteria, std::string> const &map);

template <typename T>
T uinput::get_input(std::map<T, std::string> const &map)
{
    int input;
    help::print_map(map);
    uinput::get_input(input, "Enter: ", true);
    if (help::number_between(input, 1, map.size()))
    {
        return static_cast<T>(input);
    }
    else
    {
        return uinput::get_input(map);
    }
}

std::filesystem::path uinput::get_file_path()
{
    std::string path;
    uinput::get_input(path, "Enter path to file: ");
    return std::filesystem::path(path);
}

void uinput::get_password_info(std::string &result, std::vector<std::string> const &categories)
{
    std::string name;
    std::string password;
    std::string category;
    std::string service;
    std::string login;
    uinput::get_input(name, "Enter name for the password(Required): ", true);
    uinput::get_input(password, "Enter password(Required): ", true);
    category = uinput::get_category(categories);
    uinput::get_input(service, "Enter service: ", false);
    uinput::get_input(login, "Enter login: ", false);
    result = name + constants::fdelim +
             password + constants::fdelim +
             category + constants::fdelim +
             service + constants::fdelim + login;
}

std::string uinput::get_category(std::vector<std::string> const &categories)
{
    int index = -1;
    while (!help::number_between(index, 0, categories.size() - 1))
    {
        help::print_vector(categories);
        uinput::get_input(index, "Enter category(Required): ");
    };
    return categories[index];
}
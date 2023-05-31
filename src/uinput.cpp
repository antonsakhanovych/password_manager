#include "../include/uinput.hpp"
#include "../include/constants.hpp"
#include "../include/help.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fmt/core.h>

constants::pass_command uinput::get_password_command()
{
    std::cout << R"(
    1 - to search password
    2 - to get sorted list of all passwords
    3 - to add new password
    4 - to edit existing password
    5 - to delete password
    6 - to add category 
    7 - to delete category
    8 - to exit
    )";

    int input;
    std::cin >> input;
    std::cin.ignore();
    constants::pass_command command;
    if (constants::password_command_map.find(input) == constants::password_command_map.end())
    {
        command = constants::pass_command::None;
    }
    else
    {
        command = constants::password_command_map[input];
    }

    return command;
}

void uinput::get_input(std::string &input, std::string const &message)
{
    std::cout << message << std::endl;
    std::getline(std::cin, input);
}

void uinput::get_input(int &input, std::string const &message)
{
    std::cout << message << std::endl;
    std::cin >> input;
    std::cin.ignore();
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
    uinput::get_input(name, "Enter name for the password: ");
    uinput::get_input(password, "Enter password: ");
    {
        int index = -1;
        while (!help::number_between(index, 0, categories.size() - 1))
        {
            help::printWithIndices(categories);
            uinput::get_input(index, "Enter category(number): ");
        };
        category = categories[index];
    }
    uinput::get_input(service, "Enter service: ");
    uinput::get_input(login, "Enter login: ");
    result = fmt::format("{}\t{}\t{}\t{}\t{}", name, password, category, service, login);
}
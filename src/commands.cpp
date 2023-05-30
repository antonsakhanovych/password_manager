#include "../include/commands.hpp"
#include "../include/constants.hpp"
#include <iostream>
#include <filesystem>
#include <string>

constants::command uinter::get_password_command()
{
    std::cout << R"(
    SearchPass - to search password
    SortPass - to get sorted list of all passwords
    AddPass - to add new password
    EditPass - to edit existing password
    DeletePass - to delete password
    AddCat - to add category 
    DeleteCat - to delete category
    Exit - to exit
    )";

    std::string input;
    std::cin >> input;

    constants::command command;
    if (constants::command_map.find(input) == constants::command_map.end())
    {
        command = constants::command::None;
    }
    else
    {
        command = constants::command_map[input];
    }

    return command;
}

std::filesystem::path uinter::get_file_path()
{
    std::cout << "Enter path to file: ";
    std::string path;
    std::cin >> path;
    return std::filesystem::path(path);
}
#include "../include/fileactions.hpp"
#include "../include/help.hpp"
#include "../include/uinput.hpp"
#include "../include/data.hpp"
#include "../include/constants.hpp"
#include <fmt/core.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

void fileactions::search_pass(std::filesystem::path const &path, std::string const &master_password)
{
    std::cout << "search_pass" << std::endl;
}

void fileactions::sort_pass(std::filesystem::path const &path, std::string const &master_password)
{
    std::fstream fis(path, std::ios::in);
    std::string line;
    char delimiter = master_password[master_password.size() / 2];
    while (std::getline(fis, line, delimiter))
    {
        data::xorTransform(line, master_password);
        fmt::print("{}\n", line);
    }
    fis.close();
}

void fileactions::add_pass(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password)
{
    char delimiter = master_password[master_password.size() / 2];
    data::xorTransform(toWrite, master_password);
    std::fstream fos(path, std::ios::out | std::ios::app);
    if (fos.good())
    {
        fos << toWrite << delimiter;
    }
    fos.close();
}

void fileactions::edit_pass(std::filesystem::path const &path, std::string const &master_password)
{
    std::cout << "edit_pass" << std::endl;
}

void fileactions::delete_pass(std::filesystem::path const &path, std::string const &master_password)
{
    std::cout << "delete_pass" << std::endl;
}

void fileactions::add_cat()
{
    std::cout << "add_cat" << std::endl;
}

void fileactions::delete_cat(std::filesystem::path const &path, std::string const &master_password)
{
    std::cout << "delete_cat" << std::endl;
}

void fileactions::create_file_if_not_exist(std::filesystem::path const &path)
{
    if (!std::filesystem::exists(path))
    {
        std::fstream fos(path, std::ios::out);
        fos.close();
    }
}
#include "../include/fileactions.hpp"
#include "../include/help.hpp"
#include "../include/uinput.hpp"
#include "../include/data.hpp"
#include "../include/constants.hpp"
#include "../include/password.hpp"
#include <fmt/core.h>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <filesystem>
#include <vector>
#include <fstream>

void fileactions::search_pass(std::vector<std::unique_ptr<pass::Password>> &all_passwords)
{
    std::string to_search;
    uinput::get_input(to_search, "Enter password to search(Every attribute will be matched): ", true);
    std::erase_if(all_passwords, [&to_search](std::unique_ptr<pass::Password> &password) -> bool
                  { return !password->is_match(to_search); });
    for (std::unique_ptr<pass::Password> &password : all_passwords)
    {
        std::cout << *password << std::endl;
    }
}

void fileactions::sort_pass(std::vector<std::unique_ptr<pass::Password>> &all_passwords)
{

    std::sort(all_passwords.begin(), all_passwords.end(), [](std::unique_ptr<pass::Password> &fpass, std::unique_ptr<pass::Password> &spass) -> bool
              { return fpass->get_name() < spass->get_name(); });
    for (std::unique_ptr<pass::Password> &password : all_passwords)
    {
        std::cout << *password << std::endl;
    }
}

void fileactions::add_pass(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password)
{
    char delimiter = constants::get_record_delimiter(master_password);
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

void fileactions::create_file_if_not_exist(std::filesystem::path const &path)
{
    if (!std::filesystem::exists(path))
    {
        std::fstream fos(path, std::ios::out);
        fos.close();
    }
}

void fileactions::get_all_passwords(std::filesystem::path const &path, std::string const &master_password, std::vector<std::unique_ptr<pass::Password>> &all_passwords)
{
    std::fstream fis(path, std::ios::in);
    std::string line;
    char delimiter = constants::get_record_delimiter(master_password);
    while (std::getline(fis, line, delimiter))
    {
        data::xorTransform(line, master_password);
        try
        {
            all_passwords.push_back(std::make_unique<pass::Password>(line));
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
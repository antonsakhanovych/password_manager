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
#include <chrono>
#include <cstdio>

void fileactions::search_pass(std::vector<std::unique_ptr<Password>> &all_passwords)
{
    std::string to_search;
    uinput::get_input(to_search, "Enter search: ");
    std::cout << "Search by: " << std::endl;
    constants::criteria criteria = uinput::get_input(constants::all_criterias);
    std::erase_if(all_passwords, [&to_search, &criteria](std::unique_ptr<Password> &password) -> bool
                  { return !password->is_match(to_search, criteria); });
    help::print_vector(all_passwords);
}

void fileactions::sort_pass(std::vector<std::unique_ptr<Password>> &all_passwords)
{
    std::cout << "Enter first criteria: " << std::endl;
    constants::criteria criteria1 = uinput::get_input(constants::all_criterias);
    std::cout << "Enter second criteria: " << std::endl;
    constants::criteria criteria2 = uinput::get_input(constants::all_criterias);
    std::sort(all_passwords.begin(), all_passwords.end(),
              [&criteria1, &criteria2](std::unique_ptr<Password> &fpassword, std::unique_ptr<Password> &spassword) -> bool
              { return Password::compare(*fpassword, *spassword, criteria1, criteria2); });
    help::print_vector(all_passwords);
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

void fileactions::write_time(std::filesystem::path const &path)
{
    std::filesystem::path tmpath("tmp");
    fileactions::create_file_if_not_exist(tmpath);
    std::fstream fs(path, std::ios::in);
    std::fstream tmp(tmpath, std::ios::out);
    std::string line;
    std::getline(fs, line, '\n');
    std::cout << line << std::endl;
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::tm *localTime = std::localtime(&currentTime_t);

    int hours = localTime->tm_hour;
    int minutes = localTime->tm_min;
    int seconds = localTime->tm_sec;
    std::string time = fmt::format("Last login attempt: {}:{}:{}", hours, minutes, seconds);

    tmp << time << '\n';
    tmp << fs.rdbuf();
    fs.close();
    tmp.close();
    std::filesystem::remove(path);
    std::filesystem::rename(tmpath, path);
}

void fileactions::get_all_passwords(std::filesystem::path const &path, std::string const &master_password, std::vector<std::unique_ptr<Password>> &all_passwords)
{
    std::fstream fis(path, std::ios::in);
    std::string line;
    char delimiter = constants::get_record_delimiter(master_password);
    std::getline(fis, line, '\n'); // skip first line
    while (std::getline(fis, line, delimiter))
    {
        data::xorTransform(line, master_password);
        all_passwords.push_back(std::make_unique<Password>(line));
    }
    fis.close();
}
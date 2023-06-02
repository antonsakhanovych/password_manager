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
#include <memory>

void fileactions::search_password(std::vector<std::unique_ptr<Password>> &all_passwords)
{
    std::string to_search;
    uinput::get_input(to_search, "Enter search: ");
    std::cout << "Search by: " << std::endl;
    constants::criteria criteria = uinput::get_input(constants::all_criterias);
    std::erase_if(all_passwords, [&to_search, &criteria](std::unique_ptr<Password> &password) -> bool
                  { return !password->is_match(to_search, criteria); });
    help::print_vector(all_passwords);
}

void fileactions::sort_password(std::vector<std::unique_ptr<Password>> &all_passwords)
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

void fileactions::add_password(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password)
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

void fileactions::traverse_file(std::filesystem::path const &path, std::string const &master_password,
                                std::function<void(std::fstream &, std::unique_ptr<Password> &, std::string &, char delimiter)> func)
{
    char delimiter = constants::get_record_delimiter(master_password);
    std::fstream ifs(path, std::ios::in);
    std::fstream ofs("tmp", std::ios::out);
    std::string line;
    std::getline(ifs, line, '\n');
    ofs << line << '\n';
    while (std::getline(ifs, line, delimiter))
    {
        data::xorTransform(line, master_password);
        std::unique_ptr<Password> password = std::make_unique<Password>(line);
        func(ofs, password, line, delimiter);
    }
    ifs.close();
    ofs.close();

    std::filesystem::remove(path);
    std::filesystem::rename("tmp", path);
}

void fileactions::edit_password(std::filesystem::path const &path, std::string const &master_password)
{
    std::vector<std::unique_ptr<Password>> all_passwords;
    fileactions::get_all_passwords(path, master_password, all_passwords);
    help::print_vector(all_passwords);
    int index;
    uinput::get_input(index, "Enter index of password to edit: ");
    std::unique_ptr<Password> &password_to_edit = all_passwords[index];
    fileactions::traverse_file(path, master_password,
                               [&password_to_edit, &master_password](std::fstream &ofs, std::unique_ptr<Password> &password, std::string &line, char delimiter)
                               {
        if (*password == *password_to_edit)
        {
            uinput::edit_p_instance(password_to_edit);
            std::string toWrite = password_to_edit->toString("\t");
            data::xorTransform(toWrite, master_password);
            ofs << toWrite << delimiter;
        }
        else
        {
            data::xorTransform(line, master_password);
            ofs << line << delimiter;
        } });
}

void fileactions::delete_one(std::filesystem::path const &path, std::string const &master_password, std::unique_ptr<Password> const &password_to_del)
{
    fileactions::traverse_file(path, master_password, [&password_to_del, &master_password](std::fstream &ofs, std::unique_ptr<Password> &password, std::string &line, char delimiter)
                               {
        if (*password_to_del != *password)
        {
            data::xorTransform(line, master_password);
            ofs << line << delimiter;
        } });
}

void fileactions::delete_many(std::filesystem::path const &path, std::string const &master_password)
{
    std::vector<std::unique_ptr<Password>> all_passwords;
    fileactions::get_all_passwords(path, master_password, all_passwords);
    help::print_vector(all_passwords);
    int index;
    uinput::get_input(index, "Enter index of password to delete: ");
    std::unique_ptr<Password> const &password_to_del = all_passwords[index];
    fileactions::delete_one(path, master_password, password_to_del);

    std::cout << "Do you want to continue deleting passwords? (y/n)" << std::endl;
    char answer;
    uinput::get_input(answer, "Enter answer: ");
    if (answer == 'y')
    {
        all_passwords.clear();
        fileactions::delete_many(path, master_password);
    }
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
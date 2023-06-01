#pragma once
#include "../include/password.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <memory>

namespace fileactions
{
    void create_file_if_not_exist(std::filesystem::path const &path);
    void write_time(std::filesystem::path const &path);
    void get_all_passwords(std::filesystem::path const &path, std::string const &master_password, std::vector<std::unique_ptr<Password>> &all_passwords);
    void search_pass(std::vector<std::unique_ptr<Password>> &all_passwords);
    void sort_pass(std::vector<std::unique_ptr<Password>> &all_passwords);
    void add_pass(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password);
    void edit_pass(std::filesystem::path const &path, std::string const &master_password);
    void delete_pass(std::filesystem::path const &path, std::string const &master_password);

}
#pragma once
#include "../include/password.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <memory>
#include <functional>
namespace fileactions
{
    void create_file_if_not_exist(std::filesystem::path const &path);
    void write_time(std::filesystem::path const &path);
    void get_all_passwords(std::filesystem::path const &path, std::string const &master_password, std::vector<std::unique_ptr<Password>> &all_passwords);
    void search_password(std::vector<std::unique_ptr<Password>> &all_passwords);
    void sort_password(std::vector<std::unique_ptr<Password>> &all_passwords);
    void add_password(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password);
    void edit_password(std::filesystem::path const &path, std::string const &master_password);
    void delete_one(std::filesystem::path const &path, std::string const &master_password, std::unique_ptr<Password> const &password);
    void delete_many(std::filesystem::path const &path, std::string const &master_password);
    void traverse_file(std::filesystem::path const &path, std::string const &master_password, std::function<void(std::fstream &, std::unique_ptr<Password> &, std::string &, char delimiter)> func);
    void delete_category(std::filesystem::path const &path, std::string const &master_password, std::string const &category);
}
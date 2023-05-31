#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fileactions
{
    void create_file_if_not_exist(std::filesystem::path const &path);

    void search_pass(std::filesystem::path const &path, std::string const &master_password);
    void sort_pass(std::filesystem::path const &path, std::string const &master_password);
    void add_pass(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password);
    void edit_pass(std::filesystem::path const &path, std::string const &master_password);
    void delete_pass(std::filesystem::path const &path, std::string const &master_password);
    void add_cat();
    void delete_cat(std::filesystem::path const &path, std::string const &master_password);

}
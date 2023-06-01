#pragma once
#include "constants.hpp"
#include <string>
#include <filesystem>
#include <vector>
#include <map>

namespace uinput
{

    /*!
     *  \brief get path to the password file.
     */
    std::filesystem::path get_file_path();

    void get_master_password(std::string &masterPassword);

    /*!
     *  \brief get command from user.
     */
    constants::pass_command get_password_command();

    void get_input(std::string &input, std::string const &message, bool required = true);
    void get_input(int &input, std::string const &message, bool required = true);

    template <typename T>
    T get_input(std::map<T, std::string> const &map);

    /*!
     *  funciton that gets all information about password from user and stores it in the result variable.
     */

    void get_password_info(std::string &result, std::vector<std::string> const &categories);

    std::string get_category(std::vector<std::string> const &categories);

}

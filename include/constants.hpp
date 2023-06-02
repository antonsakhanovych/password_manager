#pragma once
#include <string>
#include <map>
#include <vector>

namespace constants
{

    /*!
     *  \brief Commands that user can enter
     *
     *  This enum constains all commands that user can perform on the password file.
     */
    enum class pass_command
    {
        SearchPass = 1,
        SortPass,
        AddPass,
        EditPass,
        DeletePass,
        AddCat,
        DeleteCat,
        Exit,
        None,
    };

    extern std::map<pass_command, std::string> all_password_commands;

    extern char fdelim;

    char get_record_delimiter(std::string const &master_password);

    enum class criteria
    {
        Name = 1,
        Password,
        Category,
        Service,
        Login,
    };

    extern std::map<criteria, std::string> all_criterias;

}
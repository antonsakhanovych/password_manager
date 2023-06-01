#pragma once
#include <string>
#include <map>

namespace constants
{

    /*!
     *  \brief Commands that user can enter
     *
     *  This enum constains all commands that user can perform on the password file.
     */
    enum class pass_command
    {
        SearchPass,
        SortPass,
        AddPass,
        EditPass,
        DeletePass,
        AddCat,
        DeleteCat,
        None,
        Exit
    };

    extern std::map<int, pass_command> password_command_map;

    extern char fdelim;

    char get_record_delimiter(std::string const &master_password);

    enum class criteria
    {
        Name,
        Username,
        Password,
        Category,
        Login,
    };

    extern std::map<int, criteria> criteria_map;

}
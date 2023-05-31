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
    enum pass_command
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

}
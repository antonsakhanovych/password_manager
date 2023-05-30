#pragma once
#include <string>
#include <map>

namespace constants
{
    enum command
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

    extern std::map<std::string, command> command_map;
}
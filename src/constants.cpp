#include "../include/constants.hpp"
#include <string>

std::map<int, constants::pass_command> constants::password_command_map = {
    {1, constants::pass_command::SearchPass},
    {2, constants::pass_command::SortPass},
    {3, constants::pass_command::AddPass},
    {4, constants::pass_command::EditPass},
    {5, constants::pass_command::DeletePass},
    {6, constants::pass_command::AddCat},
    {7, constants::pass_command::DeleteCat},
    {8, constants::pass_command::Exit}};

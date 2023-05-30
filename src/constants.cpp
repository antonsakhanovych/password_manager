#include "../include/constants.hpp"
#include <string>

std::map<std::string, constants::command> constants::command_map = {
    {"SearchPass", constants::command::SearchPass},
    {"SortPass", constants::command::SortPass},
    {"AddPass", constants::command::AddPass},
    {"EditPass", constants::command::EditPass},
    {"DeletePass", constants::command::DeletePass},
    {"AddCat", constants::command::AddCat},
    {"DeleteCat", constants::command::DeleteCat},
    {"Exit", constants::command::Exit}};
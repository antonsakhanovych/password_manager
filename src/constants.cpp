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

char constants::fdelim = '\t';

char constants::get_record_delimiter(std::string const &master_password)
{
    return master_password[master_password.size() / 2];
}

std::map<int, constants::criteria> constants::criteria_map = {
    {1, constants::criteria::Name},
    {2, constants::criteria::Username},
    {3, constants::criteria::Password},
    {4, constants::criteria::Category},
    {5, constants::criteria::Login},
};
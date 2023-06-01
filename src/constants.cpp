#include "../include/constants.hpp"
#include <string>

std::map<constants::pass_command, std::string> constants::all_password_commands = {
    {constants::pass_command::SearchPass, "to search for password"},
    {constants::pass_command::SortPass, "to get sorted list of all passwords"},
    {constants::pass_command::AddPass, "to add password to the file"},
    {constants::pass_command::EditPass, "to edit existing password"},
    {constants::pass_command::DeletePass, "to delete password"},
    {constants::pass_command::AddCat, "to add category"},
    {constants::pass_command::DeleteCat, "to delete category"},
    {constants::pass_command::Exit, "to exit"}};

char constants::fdelim = '\t';

char constants::get_record_delimiter(std::string const &master_password)
{
    return master_password[master_password.size() / 2];
}

std::map<constants::criteria, std::string> constants::all_criterias = {
    {constants::criteria::Name, "by name"},
    {constants::criteria::Username, "by username"},
    {constants::criteria::Password, "by password"},
    {constants::criteria::Category, "by category"},
    {constants::criteria::Login, "by login"}};
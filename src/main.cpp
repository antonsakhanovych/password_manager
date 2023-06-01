#include "../include/uinput.hpp"
#include "../include/constants.hpp"
#include "../include/fileactions.hpp"
#include "../include/data.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

int main()
{
    std::filesystem::path path;
    std::string master_password;
    constants::pass_command pass_command;
    std::string toWrite;
    std::vector<std::unique_ptr<pass::Password>> all_passwords;
    std::vector<std::string> categories{"Social", "Email", "Bank", "Work", "Other"};

    path = uinput::get_file_path();
    fileactions::create_file_if_not_exist(path);

    uinput::get_input(master_password, "Enter master password: ");

    while (pass_command != constants::pass_command::Exit)
    {
        pass_command = uinput::get_password_command();
        switch (pass_command)
        {
        case constants::pass_command::SearchPass:
            fileactions::get_all_passwords(path, master_password, all_passwords);
            fileactions::search_pass(all_passwords);
            all_passwords.clear();
            break;

        case constants::pass_command::SortPass:
            fileactions::get_all_passwords(path, master_password, all_passwords);
            fileactions::sort_pass(all_passwords);
            all_passwords.clear();
            break;
        case constants::pass_command::AddPass:
            uinput::get_password_info(toWrite, categories);
            fileactions::add_pass(path, toWrite, master_password);
            toWrite.clear();
            break;
        case constants::pass_command::EditPass:
            fileactions::edit_pass(path, master_password);
            break;
        case constants::pass_command::DeletePass:
            fileactions::delete_pass(path, master_password);
            break;
        case constants::pass_command::AddCat:
            break;
        case constants::pass_command::DeleteCat:
            break;
        case constants::pass_command::Exit:
            exit(0);
            break;
        default:
            break;
        }
    }
}
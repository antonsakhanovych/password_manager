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
    constants::pass_command pass_command = constants::pass_command::None;

    std::vector<std::unique_ptr<Password>> all_passwords;
    std::vector<std::string> categories = {"Default"};

    path = uinput::get_file_path();
    fileactions::create_file_if_not_exist(path);
    fileactions::write_time(path);

    while (true)
    {
        try
        {
            uinput::get_input(master_password, "Enter master password: ");
            fileactions::get_all_passwords(path, master_password, all_passwords);
            // copying all categories from all_passwords to categories
            for (auto const &password : all_passwords)
            {
                categories.push_back(*password->get_field_by_criteria(constants::criteria::Category));
            }
            all_passwords.clear();
            break;
        }
        catch (MalformedPassword const &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (pass_command != constants::pass_command::Exit)
    {
        pass_command = uinput::get_password_command();
        std::string input = "";
        switch (pass_command)
        {
        case constants::pass_command::SearchPass:
            fileactions::get_all_passwords(path, master_password, all_passwords);
            fileactions::search_password(all_passwords);
            all_passwords.clear();
            break;

        case constants::pass_command::SortPass:
            fileactions::get_all_passwords(path, master_password, all_passwords);
            fileactions::sort_password(all_passwords);
            all_passwords.clear();
            break;
        case constants::pass_command::AddPass:
            uinput::get_password_info(input, categories);
            fileactions::add_password(path, input, master_password);
            break;
        case constants::pass_command::EditPass:
            fileactions::edit_password(path, master_password);
            break;
        case constants::pass_command::DeletePass:
            fileactions::delete_many(path, master_password);
            all_passwords.clear();
            break;
        case constants::pass_command::AddCat:
            std::cout << "Adding new category..." << std::endl;
            uinput::get_input(input, "Enter category name: ");
            categories.push_back(input);
            break;
        case constants::pass_command::DeleteCat:
            input = uinput::get_category(categories);
            fileactions::delete_category(path, master_password, input);
            break;
        case constants::pass_command::Exit:
            exit(0);
            break;
        default:
            break;
        }
    }
}
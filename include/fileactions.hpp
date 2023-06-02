#pragma once
#include "../include/password.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <memory>
#include <functional>

/*! @namespace fileactions
 *  @brief This namespace contains all functions related to file actions.
 */
namespace fileactions
{
    /*! @fn
     *  @brief creates file if it doesn't exist.
     *
     */
    void create_file_if_not_exist(std::filesystem::path const &path);

    /*! @fn
     *  @brief writes current time to file.
     *  @details This function writes current time(Last decryption attempt) to the first line
     *  @param path path to the file.
     */
    void write_time(std::filesystem::path const &path);

    /*! @fn
     *  @brief gets all passwords from file.
     *  @details This function gets all passwords from file and stores them in all_passwords.
     *  @param path path to the file.
     *  @param master_password master password to decrypt file.
     *  @param all_passwords vector of all passwords.
     */
    void get_all_passwords(std::filesystem::path const &path, std::string const &master_password, std::vector<std::unique_ptr<Password>> &all_passwords);

    /*! @fn
     *  @brief searches the password based on the given criteria by the user.
     *
     *  @details This function searches the password based on the given criteria by the user and displays it.
     *  @param all_passwords vector of all passwords.
     */
    void search_password(std::vector<std::unique_ptr<Password>> &all_passwords);

    /*! @fn
     *  @brief sorts all passwords.
     *
     *  @details This function sorts all passwords based on two criteria chosen by the user and displays sorted passwords.
     *  @param all_passwords vector of all passwords.
     */
    void sort_password(std::vector<std::unique_ptr<Password>> &all_passwords);

    /*! @fn
     *  @brief adds password to file.
     *
     *  @details This function adds password to file and encrypts it.
     *  @details Name, password, and category are required fields others are optional.
     *  @param path path to the file.
     *  @param toWrite string to write to file.
     *  @param master_password master password to encrypt file.
     */
    void add_password(std::filesystem::path const &path, std::string &toWrite, std::string const &master_password);

    /*! @fn
     *  @brief edits password in file.
     *
     *  @details This function edits password in file and encrypts it.
     *  @details The user will choose the password to edit in the function.
     *  @param path path to the file.
     *  @param master_password master password to encrypt file.
     *
     */
    void edit_password(std::filesystem::path const &path, std::string const &master_password);

    /*! @fn
     *  @brief deletes password from file.
     *
     *  @details This function deletes password from file.
     *
     *  @param path path to the file.
     *  @param master_password master password to access file.
     *  @param password password to delete.
     */
    void delete_one(std::filesystem::path const &path, std::string const &master_password, std::unique_ptr<Password> const &password);

    /*! @fn
     * @brief deletes password from file chosen by the user.
     *
     * @details This function prompts the user to choose the password to delete and then deletes it using delete_one function.
     *
     * @param path path to the file.
     * @param master_password master password to access file.
     *
     */
    void delete_many(std::filesystem::path const &path, std::string const &master_password);

    /*! @fn
     *   @brief traverses file and calls func for each line of the file.
     *   @details This function traverses file and calls func for each line of the file.
     *   @details This function is used in delete_one and edit_password.
     *   @param path path to the file.
     *   @param master_password master password to access file.
     *   @param func function to call for each line of the file. This function accepts fstream which it writes edited or skips(in case of deleting) password to the file.
     *
     */
    void traverse_file(std::filesystem::path const &path, std::string const &master_password, std::function<void(std::fstream &, std::unique_ptr<Password> &, std::string &, char delimiter)> func);

    /*! @fn
     *  @brief deletes all passwords that belong to the given category.
     *
     *  @details This function deletes all passwords that belong to the category chosen by the user.
     *
     *  @param path path to the file.
     *  @param master_password master password to access file.
     *  @param category category to delete.
     */
    void delete_category(std::filesystem::path const &path, std::string const &master_password, std::string const &category);
}
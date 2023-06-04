#pragma once

#include "password.hpp"
#include "constants.hpp"
#include <string>
#include <filesystem>
#include <vector>
#include <map>

/*! @namespace uinput
 *  @brief namespace for user input functions.
 */
namespace uinput
{

    /*! @fn
     *  @brief get path to the password file.
     *  @return path to the password file.
     */
    std::filesystem::path get_file_path();

    /*! @fn
     *  @brief get master password from user.
     *  @param masterPassword string that will contain master password.
     *
     */
    void get_master_password(std::string &masterPassword);

    /*! @fn
     *  @brief get command from user.
     *
     *  @details This function gets command from user and returns it.
     *  @return command.
     */
    constants::pass_command get_password_command();

    /*! @fn
     *  @brief get input from user.
     *
     *  @details This function gets input from the user and ensures that it's not empty.
     *  @param input string that will be modified inside the function.
     */
    void get_input(std::string &input, std::string const &message, bool required = true);

    /*! @fn
     *  @brief get input from user.
     *
     *  @details This function gets input from the user and ensures that it's not empty.
     *
     *  @param input string that will be modified inside the function.
     *  @param message message that will be displayed to the user.
     *  @param required if true, the function will ask for input until it's not empty.
     *  @tparam T type of the input.
     *
     */
    template <typename T>
    void get_input(T &input, std::string const &message, bool required = true);

    /*! @fn
     *  @brief get input from user and return mapping to string.
     *
     *  @details This function gets input from the user and uses the input to get value from the map provided.
     *
     *  @param map map that will be used to returnn
     *  @tparam T type of the input.
     */

    template <typename T>
    T get_input(std::map<T, std::string> const &map);

    /*! @fn
     *  @brief get input from user
     *
     * @details gets input from the user and ensures that it's not empty and is in the range.
     * @param input input that will be modified inside the function.
     * @param message message that will be displayed to the user.
     * @param required if true, the function will ask for input until it's not empty.
     * @param max_value maximum value that the input can be.
     *
     */
    void get_input(int &input, std::string const &message, bool required, int max_value);

    /*! @fn
     *  @brief get password info from user and store it in the result variable
     *
     * @param result result field that will store the result of the user input.
     * @param categories categories that will be displayed to the user to choose from.
     */
    void get_password_info(std::string &result, std::vector<std::string> const &categories);

    /*! @fn
     *  @brief get category from user.
     *
     *  @param categories categories that will be displayed to the user to choose from.
     *  @return category that the user chose.
     *
     */
    std::string get_category(std::vector<std::string> const &categories);

    /*! @fn
     *  @brief edit password instance.
     *
     *  @details This function gets input from the user and uses the input to modify the password instance.
     *
     *  @param password password instance that will be modified.
     */
    void edit_p_instance(std::unique_ptr<Password> &password);

}

#pragma once
#include <string>
#include <map>
#include <vector>

/*! @namespace constants
 *  @brief Namespace that contains all constants used in the program.
 */

namespace constants
{

    /*! @enum
     *  @brief Commands that user can enter
     *
     *  @details This enum constains all commands that user can perform on the password file.
     *
     */
    enum class pass_command
    {
        SearchPass = 1,
        SortPass,
        AddPass,
        EditPass,
        DeletePass,
        AddCat,
        DeleteCat,
        Exit,
        None,
    };

    /*!
     *  @brief Map that contains all commands that user can perform on the password file.
     *
     *  @details This map is used to map users input(int) to the command that the program should perform.
     *
     */
    extern std::map<pass_command, std::string> all_password_commands;

    /*!
     *  @brief Delimiter that is used to separate fields in the password file.
     *
     *
     */
    extern char fdelim;

    /*! @fn
     *  @brief get delimiter that is used to separate fields in the password file.
     *
     *  @details This function returns delimiter that is used to separate fields in the password file.
     *  @details The delimiter is calculated from the master password.
     *
     *  @param master_password master password that is used to encrypt the password file.
     */
    char get_record_delimiter(std::string const &master_password);

    /*! @enum
     *  @brief Criteria that user can use to search and sort passwords.
     *
     *  @details This enum contains all properties of the password.
     *
     */
    enum class criteria
    {
        Name = 1,
        Password,
        Category,
        Service,
        Login,
    };

    /*!
     *  @brief Map that contains all criteria that user can use to search for password.
     *
     * This map is used to map criteria to std::string to output it to the user.
     *
     */
    extern std::map<criteria, std::string> all_criterias;

}
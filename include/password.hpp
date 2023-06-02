#pragma once
#include "constants.hpp"
#include <string>
#include <filesystem>

/*! @class Password
 *
 *  @brief Class that represents a password.
 *  @details This class is used to store information about a password.
 *
 */
class Password
{
private:
    std::string name;
    std::string password;
    std::string category;
    std::string service;
    std::string login;

public:
    /*! @fn
     *  @brief Constructor of Password class.
     *  @details This constructor is used to create a Password object from a data seperated by delimiter.
     *  @param data string that contains information about a password.
     */
    Password(std::string const &data);

    /*! @fn
     *  @brief Constructor of Password class.
     *  @details This constructor is used to create a Password object from given parameters.
     *  @param name name of the password.
     *  @param password password.
     *  @param category category of the password.
     *  @param service service of the password.
     *  @param login login of the password.
     */
    Password(std::string const &name, std::string const &password, std::string const &category, std::string const &service, std::string const &login);

    /*! @fn
     *  @brief Destructor of Password class.
     *  @details Default destructor of Password class.
     */
    ~Password();

    /*! @fn
     *  @brief Function that returns string representation of the password.
     *  @details This function returns string representation of the password.
     *  @param delimiter delimiter that is used to seperate fields of the password.
     *  @return string representation of the password.
     */
    std::string toString(std::string delimiter) const;

    /*! @fn
     *
     *  @brief Overloaded operator<< for Password class.
     *  @details This function is used to print Password object.
     *
     *  @param os output stream.
     *  @param pass Password object to print.
     *
     */
    friend std::ostream &operator<<(std::ostream &os, std::unique_ptr<Password> const &pass);

    /*! @fn
     *  @brief Overloaded operator== for Password class.
     *  @details This function is used to compare two Password objects.
     *
     *  @param other Password object to compare.
     *  @return true if Password objects are equal, false otherwise.
     */
    bool operator==(Password const &other) const;

    /*! @fn
     *  @brief Overloaded operator!= for Password class.
     *  @details This function is used to compare two Password objects.
     *
     *  @param other Password object to compare.
     *  @return true if Password objects are not equal, false otherwise.
     */
    bool operator!=(Password const &other) const;

    /*! @fn
     *  @brief Function that checks if property of the password has a substring of search.
     *
     *  @param search string to search.
     *  @param criteria criteria to search.
     *  @return true if field has a substring of search, false otherwise.
     */
    bool is_match(std::string const &search, constants::criteria criteria) const;

    /*! @fn
     *  @brief Function that returns field of the password based on the criteria.
     *
     *  @param criteria criteria to get field.
     *  @return const pointer to the field.
     */

    std::string const *get_field_by_criteria(constants::criteria criteria) const;

    /*! @fn
     *  @brief Function that compares two Password objects based on the criteria.
     *
     *  @param p1 first Password object to compare.
     *  @param p2 second Password object to compare.
     *  @param criteria1 criteria to compare first Password object.
     *  @param criteria2 criteria to compare second Password object.
     *  @return true if first Password object is less than second Password object, false otherwise.
     */
    static bool compare(Password const &p1, Password const &p2, constants::criteria criteria1, constants::criteria criteria2);
};

/*! @class MalformedPassword exception
 *
 *  @brief Class that represents an exception.
 *  @details This class is used to represent an exception that is thrown when the data given to the Password constructor is not of the right formating.
 *
 */
class MalformedPassword : std::exception
{
public:
    /*! @fn
     *  @brief function that overrides what() function from std::exception.
     *
     */
    const char *what() const noexcept;
};
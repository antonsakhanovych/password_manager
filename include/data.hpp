#pragma once
#include <string>

/*! @namespace data
 *  @brief namespace that contains functions that are used to manipulate data.
 */
namespace data
{
    /*! @fn
     *  @brief encrypts or decrypts string using xor algorithm.
     *
     *  @details This function encrypts and decrypts data with the given key using xor algorithm.
     *
     *  @param toTransform string to encrypt/decrypt.
     *  @param key key that is used to encrypt the string(aka master password).
     */
    void xorTransform(std::string &toTransform, std::string const &key);

    /*! @fn
     *  @brief splits record into fields and stores them in the given variables.
     *
     *  @param record record to split.
     *  @param name variable that will store name of the password.
     *  @param password variable that will store password.
     *  @param category variable that will store category of the password.
     *  @param service variable that will store service of the password.
     *  @param login variable that will store login of the password.
     */

    void split_record(std::string const &record, std::string &name, std::string &password, std::string &category, std::string &service, std::string &login);
}

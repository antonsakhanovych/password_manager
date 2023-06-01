#pragma once
#include <string>

namespace data
{
    void xorTransform(std::string &toTransform, std::string const &key);

    void split_record(std::string const &record, std::string &name, std::string &password, std::string &category, std::string &service, std::string &login);
}

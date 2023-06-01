#pragma once
#include <string>

namespace pass
{
    class Password
    {
    private:
        std::string data;
        std::string name;
        std::string password;
        std::string category;
        std::string service;
        std::string login;

    public:
        Password(std::string const &data);
        ~Password();
        std::string get_name() const;
        friend std::ostream &operator<<(std::ostream &os, Password const &pass);
        bool is_match(std::string const &search) const;
    };

}

#include "../include/help.hpp"

template void help::print_map<constants::pass_command>(std::map<constants::pass_command, std::string> const &map);
template void help::print_map<constants::criteria>(std::map<constants::criteria, std::string> const &map);

template <typename T>
void help::print_map(std::map<T, std::string> const &map)
{
    std::cout << std::endl;
    for (auto const &pair : map)
    {
        std::cout << static_cast<int>(pair.first) << " : " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

template void help::print_vector<std::string>(std::vector<std::string> const &vector);

template void help::print_vector<std::unique_ptr<Password>>(std::vector<std::unique_ptr<Password>> const &vector);

template <typename T>
void help::print_vector(std::vector<T> const &vector)
{
    std::cout << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << i << " : " << vector[i] << std::endl;
    }
    std::cout << std::endl;
}

bool help::number_between(int number, int lower, int upper)
{
    return number >= lower && number <= upper;
}

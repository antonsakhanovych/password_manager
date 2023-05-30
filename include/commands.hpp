#pragma once
#include "constants.hpp"
#include <string>
#include <filesystem>

namespace uinter
{

    std::filesystem::path get_file_path();
    constants::command get_password_command();
}

#include "replace.hpp"
#include <string>


std::string my_replace(std::string content, const std::string &to_find, const std::string &to_replace)
{
    std::string new_string;
    size_t start_pos = 0;
    size_t pos;

    if(to_find.empty())
        return content;
    while ((pos = content.find(to_find, start_pos)) != std::string::npos)
    {
        new_string += content.substr(start_pos, pos - start_pos);
        new_string += to_replace;
        start_pos = pos + to_find.length();
    }

    new_string += content.substr(start_pos);
    return new_string;
}

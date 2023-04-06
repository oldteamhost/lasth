#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split_names(std::string names)
{
    std::stringstream ss(names);
    std::vector<std::string> result;
    std::string name;

    while (std::getline(ss, name, ',')) {
        result.push_back(name);
    }

    return result;
}

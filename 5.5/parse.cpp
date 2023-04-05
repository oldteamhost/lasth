#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split_names(std::string names)
{
    std::stringstream ss(names); // создаем поток из входной строки
    std::vector<std::string> result;
    std::string name;

    while (std::getline(ss, name, ',')) { // разбиваем строку по запятым
        result.push_back(name); // добавляем имя в массив
    }

    return result;
}

#include "input.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "menu.h"

void file_import::import_file(const std::string& filename, std::vector<std::string>& words, std::vector<std::string>& links) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        file_not_found(filename.c_str());
        return;
    }

    std::string line;
    int i = 0;
    while (std::getline(file, line) && i < MAX_LINES) {
        std::istringstream iss(line);
        std::string word, link;
        if (iss >> word >> link) {
            words.push_back(word);
            links.push_back(link);
            i++;
        }
    }
}

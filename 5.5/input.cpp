#include "input.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void file_import::import_file(const std::string& filename, std::vector<std::string>& words, std::vector<std::string>& links) {
    std::ifstream file(filename);
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

#include <iostream>
#include <vector>

#define MAX_LINES 10000

class file_import{
public:
    void import_file(const std::string& filename, std::vector<std::string>& words, std::vector<std::string>& links);

};

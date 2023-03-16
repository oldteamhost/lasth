#pragma once
#include <iostream>
class social
{
public:
    std::string array[500];
    short loop = 0;
    const char* path;
    int mode;
    bool initFile();
    void setPath (const char* path);
private:
    std::string line;
};


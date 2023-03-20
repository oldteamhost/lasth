#pragma once
#include <iostream>
class social
{
public:
    short loop = 0;
    const char* path;
    int mode;
    std::string array[9999];

    short loopCustom = 0;
    const char* pathCustom;
    int modeCustom;
    std::string arrayCustom[9999];

    bool initFile();
    void setPath(const char* path);

    bool initCustomFile();
    void setCustomPath(const char* path);
private:
    std::string line;
    std::string lineCustom;
};


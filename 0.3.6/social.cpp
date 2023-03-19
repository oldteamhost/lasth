#include "social.h"
#include <fstream>
#include <string>
#include <iostream>

bool social::initFile()
{
    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, line);
            array[loop] = line;
            loop++;
        }
        myfile.close();
        if (loop <= 1)
        {
            if (mode == 0){
                std::cout << "[*] data/social.txt empty....\n";
            }
            else {
                std::cout << "[*] " << path << " empty....\n";
            }
            exit(1);
            return false;
        }
        return true;
    }
    else
    {
        if (mode == 0){
            std::cout << "[-] data/social.txt not found!\n";
            std::ofstream oFile("data/social.txt");
            std::cout << "[*] data/social.txt created....\n";
        }
        else {
            std::cout << "[-] " << path << " not found!\n";
        }
        exit(1);
        return false;
    }
}

void social::setPath(const char *path)
{
    this->path = path;
}

bool social::initCustomFile()
{
    std::ifstream myfile(pathCustom);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, lineCustom);
            arrayCustom[loopCustom] = lineCustom;
            loopCustom++;
        }
        myfile.close();
        if (loopCustom <= 1)
        {
            std::cout << "[*] " << pathCustom << " empty....\n";
            exit(1);
            return false;
        }
        return true;
    }
    else
    {
        std::cout << "[-] " << pathCustom << " not found!\n";
        exit(1);
        return false;
    }
}

void social::setCustomPath(const char *path)
{
    pathCustom = path;
}

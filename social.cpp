#include "social.h"
#include <fstream>
#include <string>
#include <iostream>

bool social::initFile()
{
    std::ifstream myfile("data/social.txt");
    if (myfile.is_open()) {
        while (!myfile.eof())
        {
            getline(myfile, line);
            array[loop] = line;
            loop++;
        }
        myfile.close();
        if (loop <= 1) {
            std::cout << "[*]: data/social.txt empty....\n";
            exit(1);
            return false;
        }
        return true;
    }
    else {
        std::cout << "[-]: data/social.txt not found!\n";
        std::ofstream oFile("data/social.txt");
        std::cout << "[*]: data/social.txt created....\n";
        exit(1);
        return false;
    }
}

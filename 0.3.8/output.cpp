#include "includes/output.h"
#include "includes/print.h"
#include <fstream>
#include <iostream>

print prtn;

void output::initFolders()
{
    system("mkdir -p data");
    system("mkdir -p out");
}

void output::initFoldersAdvanced(std::string name)
{
    std::string result1 = "mkdir -p out/" + name;
    std::string result2 = "mkdir -p out/" + name + "/pages";
    
    system(result1.c_str());
    system(result2.c_str());
}

bool output::writeMode(const char *mode, const char *path)
{
    std::ofstream file;
    file.open(path, std::ofstream::app);
    if (!file.is_open())
    {
        prtn.printError(path,1);
        std::cin.get();
        return false;
    }
    else
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        tm *gmtm = gmtime(&now);
        dt = asctime(gmtm);


        file << "\n" << dt;
        std::string modeTemp = mode;

        if (modeTemp == "debug")
        {
            file << "Mode: debug - (Saving and outputting even pages that are not working).\n\n";
        }
        else if (modeTemp == "normal")
        {
            file << "Mode: normal - (Save working hosts only).\n\n";
        }
        else if (modeTemp == "custom")
        {
            file << "Mode: custom_code - (Save working hosts only you code).\n\n";
        }
    }
    file.close();
    return true;
}

bool output::writeStringTxt(const char *path, const char *str, long responceCode)
{
    std::ofstream file;
    file.open(path, std::ofstream::app);
    if (!file.is_open())
    {
        prtn.printError(path,1);
        std::cin.get();
        return false;
    }
    else
    {
        file << "Code >> " << responceCode << " ";
        file << str;
        file << "\n";
    }
    file.close();
    return true;
}

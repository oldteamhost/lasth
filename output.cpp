#include "output.h"
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <bits/stdc++.h>

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

void output::printOutput(long code, const char *mode, const char *link, bool status)
{
    if (status == true)
    {
        std::cout << "[+] " << code << " << " << mode << link << std::endl;
    }
    else
    {
        std::cout << "[-] " << code << " << " << mode << link << std::endl;
    }
}

void output::printMain(const char *name)
{
    std::cout << "\n[*] Checking nickname " << name << ":\n\n";
}

void output::printEnd(int count)
{
    std::cout << "\n[*] Search completed with " << count << " results\n\n";
}

void output::printHelpMenu()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "LastTrench: Finding what the person left behind online.\n\n";
    std::cout << "\nusage: ./Lastn  [-h] [--version] [-n NICKNAME] [--txt]\n";
    std::cout << "                [-d] [-t TIMEOUT] [-p PROTC://IP:PORT]\n";
    std::cout << "                [--html] [--ru]\n\n\n";
    std::cout << "optional arguments:\n";
    std::cout << "  -n, --name            Set target name.\n";
    std::cout << "  -h, --help            Show this help message and exit.\n";
    std::cout << "  --version, -v         Display version information and dependencies.\n";
    std::cout << "  -d, --db, -debug      Saving and outputting even pages that are not working.\n";
    std::cout << "  -t, --timeout         Set a delay when receiving a page.\n";
    std::cout << "  -x, --oX              Save the output to a text file.\n";
    std::cout << "  -l, --oL              Save output to html.\n";
    std::cout << "  -p, --proxy           Using proxy server.\n";
    std::cout << "  --ru                  Это меню на нормальной языке).\n";
}

void output::printHelpMenuRu()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "LastTrench: Finding what the person left behind online.\n\n";
    std::cout << "\nИспользывание: ./Lastn  [-h] [--version] [-n ЦЕЛЬ] [--txt]\n";
    std::cout << "                        [-d] [-t Задержка] [-p ПРОТК://АЙПИ:ПОРТ]\n";
    std::cout << "                        [--html] [--ru]\n\n\n";
    std::cout << "Описание аргументов:\n";
    std::cout << "  -n, --name            Установить цель.\n";
    std::cout << "  -h, --help            Показать меню на пендоском.\n";
    std::cout << "  --version, -v         Показать боль создателя.\n";
    std::cout << "  -d, --db, -debug      Сохранять и выводить даже не рабоющие хосты.\n";
    std::cout << "  -t, --timeout         Установить задержку перед проверкой хоста.\n";
    std::cout << "  -x, --oX              Сохранять вывод в текстовый файл.\n";
    std::cout << "  -l, --oL              Сохранять хосты в файл html.\n";
    std::cout << "  -p, --proxy           Использывать прокси сервер.\n";
    std::cout << "  --ru                  Ты уже в нормальном меню.\n";
}

bool output::writeMode(const char *mode, const char *path)
{
    std::ofstream file;
    file.open(path, std::ofstream::app);
    if (!file.is_open())
    {
        std::cout << "ERROR:" << path << "not found!";
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
        std::cout << "ERROR:" << path << "not found!";
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

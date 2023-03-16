#include "print.h"
#include "lib/termcolor.hpp"

#define VERSION_PROGRAM "oldteam 0.3.3"

using namespace termcolor;

void print::printHelpMenu()
{
    setlocale(LC_ALL, "Russian");

    if (colorActive)
    {
        std::cout << bold << "LastTrench:" << reset << " Finding what the person left behind online.\n\n";
    }
    else
    {
        std::cout << "LastTrench: Finding what the person left behind online.\n\n";
    }
    std::cout << "\nusage: ./Lastn [-h] [--version] [-n NICKNAME] [--txt]\n";
    std::cout << "               [-d] [-t TIMEOUT] [-p PROTC://IP:PORT]\n";
    std::cout << "               [--html] [--ru] [--color]\n\n\n";
    std::cout << "argumentation description:\n";
    std::cout << "  -n, --name            Set target name.\n";
    std::cout << "  -h, --help            Show this help message and exit.\n";
    std::cout << "  --version, -v         Display version information and dependencies.\n";
    std::cout << "  -t, --timeout         Set a delay when receiving a page.\n";
    std::cout << "  -p, --proxy           Using proxy server.\n";
    std::cout << "  --debug               Saving and outputting even pages that are not working.\n";
    std::cout << "  --html                Save the output to a text file.\n";
    std::cout << "  --txt                 Save output to html.\n";
    std::cout << "  --path                Specify your file with links.\n";
    std::cout << "  --color               Disable color.\n";
    std::cout << "  --ru                  Это меню на нормальной языке).\n";
}

void print::printHelpMenuRu()
{
    setlocale(LC_ALL, "Russian");
    if (colorActive)
    {
        std::cout << bold << "LastTrench:" << reset << " Finding what the person left behind online.\n\n";
    }
    else
    {
        std::cout << "LastTrench: Finding what the person left behind online.\n\n";
    }
    std::cout << "\nюзать: ./Lastn [-h] [--version] [-n ЦЕЛЬ] [--txt]\n";
    std::cout << "               [-d] [-t МС] [-p ПРОТЛ://АЙПИ:ПОРТ]\n";
    std::cout << "               [--html] [--ru] [--color]\n\n\n";
    std::cout << "описание аргументов:\n";
    std::cout << "  -n, --name            Установить цель.\n";
    std::cout << "  -h, --help            Показать меню на пендоском.\n";
    std::cout << "  --version, -v         Показать боль создателя.\n";
    std::cout << "  -t, --timeout         Установить загрузку, при получение старницы.\n";
    std::cout << "  -p, --proxy           Использывать прокси сервер (sock4://IP:PORT).\n";
    std::cout << "  --debug               Выводить и сохранять даже не рабочие страницы.\n";
    std::cout << "  --html                Сохранять вывод в html.\n";
    std::cout << "  --txt                 Сохранять вывод в текстовый документ.\n";
    std::cout << "  --path                Указать свой файл с ссылками.\n";
    std::cout << "  --color               Выключить цвета.\n";
    std::cout << "  --ru                  Ты уже в нормальном меню.\n";
}

void print::printResults(int count)
{
    if (colorActive)
    {
        std::cout << yellow << bold << "[*] " << reset << "Search completed with " << bold << count - 1 << reset << " results\n";
    }
    else
    {
        std::cout << "[*] Search completed with " << count - 1 << " results\n";
    }
}

void print::printInfo(std::string name)
{
    if (colorActive)
    {
        std::cout << yellow << bold << "[*] " << reset << "Checking " << bold << name << reset << ":\n";
    }
    else
    {
        std::cout << "[*] Checking " << name << ":\n";
    }
}

void print::printPreHelp()
{
    std::cout << "usage: ./lastn [-h or --help]\n";
}

void print::printVersion()
{
    std::cout << VERSION_PROGRAM << std::endl;
}

void print::printError(std::string temp, int mode)
{
    if (mode == 1)
    {
        if (colorActive)
        {
            std::cout << bold << bright_red << "[-]" << reset << temp << "not found!";
        }
        else
        {
            std::cout << "[-]" << temp << "not found!";
        }
    }
    else if (mode == 2)
    {
        if (colorActive)
        {
            std::cout << yellow << "[*] " << reset << "You did not specify a timeout, so the standard timeout is 80ms.\n";
        }
        else
        {
            std::cout << "[*] You did not specify a timeout, so the standard timeout is 80ms.\n";
        }
    }
}

void print::printOutput(long code, const char *mode, const char *link, bool status)
{
    if (status == true)
    {
        if (colorActive)
        {
            std::cout << bright_green << bold << "[+] " << reset << bold << code << reset << " | " << mode << bright_green << link << std::endl
                      << reset;
        }
        else
        {
            std::cout << "[+] " << code << " | " << mode << link << std::endl;
        }
    }
    else
    {
        if (colorActive)
        {
            std::cout << bright_red << bold << "[-] " << reset << bold << code << reset << " | " << mode << bright_red << link << std::endl
                      << reset;
        }
        else
        {
            std::cout << "[-] " << code << " | " << mode << link << std::endl;
        }
    }
}

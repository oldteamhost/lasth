#include <iostream>
class print
{
public:
    bool colorActive = true;
    void printHelpMenu();
    void printHelpMenuRu();
    void printResults(int count);
    void printInfo(std::string name);
    void printPreHelp();
    void printVersion();
    void printError(std::string temp, int mode);
    void printOutput(long code, const char *mode, const char *link, bool status);

};

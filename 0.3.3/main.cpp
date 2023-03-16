#include <iostream>
#include "processing.h"
#include <stdio.h>
#include <getopt.h>
#include "output.h"
#include "social.h"
#include "connect.h"
#include "generate.h"
#include "print.h"
#include <thread>
#include <chrono>

output out;
social soc;
processing pro;
connect con;
generate gen;
print prt;

int main(int argc, char *argv[])
{
    const char *short_options = "n:u:hvt::p:";

    const struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {"debug", no_argument, NULL, 0},
        {"db", no_argument, NULL, 6},
        {"timeout", optional_argument, NULL, 't'},
        {"ru", no_argument, NULL, 4},
        {"txt", no_argument, NULL, 1},
        {"html", no_argument, NULL, 2},
        {"color", no_argument, NULL, 3},
        {"path", required_argument, NULL, 5},
        {"name", required_argument, NULL, 'n'},
        {"username", required_argument, NULL, 'u'},
        {"proxy", required_argument, NULL, 'p'},
        {NULL, 0, NULL, 0}};

    if (argc <= 1)
    {
        prt.printHelpMenu();
        std::cin.get();
        return true;
    }

    else
    {
        srand(time(nullptr));
        out.initFolders();
        int rez;
        int option_index = 0;

        while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
        {
            if (rez == -1)
                break;

            switch (rez)
            {
            case 0:
                pro.debugTemp = "1";
                break;
            case 1:
                pro.txtTemp = "1";
                break;
            case 2:
                pro.htmlTemp = "1";
                break;
            case 3:
                prt.colorActive = false;
                break;
            case 4:
                prt.printHelpMenuRu();
                break;
            case 5:
                pro.pathTemp = "1";
                pro.pathTempTemp = optarg;
                break;
            case 6:
                pro.debugTemp = "1";
                break;
            case 'h':
                prt.printHelpMenu();
                exit(0);
                break;
            case 'v':
                prt.printVersion();
                exit(0);
                break;
            case 'n':
                pro.nameTemp = optarg;
                break;
            case 'u':
                pro.nameTemp = optarg;
                break;
            case 't':
                pro.timeoutTempTemp = "1";
                if (optarg != NULL)
                {
                    pro.timeoutTemp = optarg;
                }
                else
                {
                    pro.timeoutTemp = "80";
                    prt.printError("", 2);
                }
                break;
            case 'p':
                pro.proxyTemp = "1";
                pro.proxyTempTemp = optarg;
                break;
            case '?':
            default:
            {
                prt.printPreHelp();
                break;
            }
            }
        }
        if (pro.pathTemp == "1")
        {
            soc.mode = 1;
            soc.setPath(pro.pathTempTemp);
        }
        else
        {
            soc.mode = 0;
            soc.setPath("data/social.txt");
        }

        if (soc.initFile())
        {
            int writeTemp = 0;
            std::string nameTempTemp = pro.nameTemp;
            std::string timeout = pro.timeoutTemp;
            std::string path = "out/" + nameTempTemp + "/" + nameTempTemp + ".txt";

            out.initFoldersAdvanced(nameTempTemp);

            prt.printInfo(nameTempTemp);

            for (int i = 0; i < soc.loop; i++)
            {
                std::string result = soc.array[i].c_str() + nameTempTemp;
                const char *link = result.c_str();

                long temp;

                if (pro.proxyTemp == "1")
                {
                    temp = con.ResponseCode(link, true, pro.proxyTempTemp);
                }
                else
                {
                    temp = con.ResponseCode(link, true, "");
                }

                if (pro.timeoutTempTemp == "1")
                {
                    int timeoutConvert = stoi(timeout);
                    std::this_thread::sleep_for(std::chrono::milliseconds(timeoutConvert));
                }

                if (pro.debugTemp == "1")
                {
                    if (temp == 200)
                    {
                        if (pro.txtTemp == "1")
                        {
                            if (writeTemp == 1)
                            {
                                out.writeStringTxt(path.c_str(), link, temp);
                            }
                            else
                            {
                                out.writeMode("debug", path.c_str());
                                out.writeStringTxt(path.c_str(), link, temp);
                                writeTemp = 1;
                            }
                        }
                        else
                        {
                            prt.printOutput(temp, "", link, true);
                        }
                        pro.currect++;
                    }
                    else
                    {
                        if (pro.htmlTemp == "1")
                        {
                            std::string tempStr = gen.generateString(5, DICTIONARY);
                            std::string pathHtml = "out/" + nameTempTemp + "/pages/" + tempStr + ".html";
                            con.downloadPage(link, pathHtml.c_str());
                        }

                        if (pro.txtTemp == "1")
                        {
                            if (writeTemp == 1)
                            {
                                out.writeStringTxt(path.c_str(), link, temp);
                            }
                            else
                            {
                                out.writeMode("debug", path.c_str());
                                out.writeStringTxt(path.c_str(), link, temp);
                                writeTemp = 1;
                            }
                        }
                        prt.printOutput(temp, "", link, false);
                    }
                }
                else
                {
                    if (temp == 200)
                    {

                        if (pro.htmlTemp == "1")
                        {
                            std::string tempStr = gen.generateString(5, DICTIONARY);
                            std::string pathHtml = "out/" + nameTempTemp + "/pages/" + tempStr + ".html";
                            con.downloadPage(link, pathHtml.c_str());
                        }

                        if (pro.txtTemp == "1")
                        {
                            if (writeTemp == 1)
                            {
                                out.writeStringTxt(path.c_str(), link, temp);
                            }
                            else
                            {
                                out.writeMode("normal", path.c_str());
                                out.writeStringTxt(path.c_str(), link, temp);
                                writeTemp = 1;
                            }
                        }
                        pro.currect++;
                        prt.printOutput(temp, "", link, true);
                    }
                }
            }
        }
        prt.printResults(pro.currect);

        return 0;
    }
}
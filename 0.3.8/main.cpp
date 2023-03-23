#include <iostream>
#include "includes/processing.h"
#include <getopt.h>
#include "includes/output.h"
#include "includes/social.h"
#include "includes/connect.h"
#include "includes/generate.h"
#include "includes/print.h"
#include <thread>
#include <chrono>
#include "lib/termcolor.hpp"

using namespace termcolor;

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
        {"debug", no_argument, NULL, 0},
        {"txt", no_argument, NULL, 1},
        {"html", no_argument, NULL, 2},
        {"color", no_argument, NULL, 3},
        {"ru", no_argument, NULL, 4},
        {"path", required_argument, NULL, 5},
        {"db", no_argument, NULL, 6},
        {"code", required_argument, NULL, 7},
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {"timeout", optional_argument, NULL, 't'},
        {"name", required_argument, NULL, 'n'},
        {"username", required_argument, NULL, 'u'},
        {"proxy", required_argument, NULL, 'p'},
        {NULL, 0, NULL, 0}};

    if (argc <= 1)
    {
        prt.printHelpMenu();
        return true;
    }

    else
    {
        int rez;
        int option_index = 0;

        srand(time(nullptr));
        out.initFolders();

        while (rez = getopt_long(argc, argv, short_options, long_options, &option_index) != EOF)
        {
            if (rez == -1)
                break;

            switch (rez)
            {
            case 0:
                pro.enableDebug();
                break;
            case 1:
                pro.enableTxt();
                break;
            case 2:
                pro.enableHtml();
                break;
            case 3:
                prt.colorActive = false;
                break;
            case 4:
                prt.printHelpMenuRu();
                exit(0);
                break;
            case 5:
                pro.enablePath();
                pro.setPath(optarg);
                break;
            case 6:
                pro.enableDebug();
                break;
            case 7:
                pro.enableCode();
                pro.setResponceCode(std::atoi(optarg));
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
                pro.enableName();
                pro.setName(optarg);
                break;
            case 'u':
                pro.enableName();
                pro.setName(optarg);
                break;
            case 't':
                pro.enableTimeout();

                if (optarg != NULL)
                {
                    pro.setTimeout(optarg);
                }
                else
                {
                    pro.setTimeout("80");
                    prt.printError("", 2);
                }

                break;
            case 'p':
                pro.enableProxy();
                pro.setProxy(optarg);
                break;
            case '?':
            default:
            {
                prt.printPreHelp();
                break;
            }
            }
        }
        // Check_net
        if (con.responseCode("https://google.com", false, "") == 1)
        {
            prt.printError(" Connection failed, check net!\n", 3);
            exit(1);
        }

        // Check_proxy. Don`t work)))
        if (pro.checkProxy())
        {
            if (con.responseCode("https://google.com", false, pro.getProxy()) == 1)
            {
                prt.printError(" Proxy connection failed!\n", 3);
                exit(1);
            }
        }

        if (pro.checkPath())
        {
            soc.mode = 1;
            soc.setPath(pro.getPath());
        }
        else
        {
            soc.mode = 0;
            soc.setPath("data/social.txt");
        }
        auto begin = std::chrono::steady_clock::now();
        if (soc.initFile())
        {
            int writeTemp = 0;

            std::string nameTempTemp = pro.getName();
            std::string timeoutTempTemp = pro.getTimeout();
            std::string pathTempTemp = "out/" + nameTempTemp + "/" + nameTempTemp + ".txt";

            out.initFoldersAdvanced(nameTempTemp);
            prt.printInfo(nameTempTemp);

            for (int i = 0; i < soc.loop; i++)
            {
                long responceCodeTemp;
                std::string result = soc.array[i].c_str() + nameTempTemp;
                const char *link = result.c_str();

                if (pro.checkProxy())
                {
                    responceCodeTemp = con.responseCode(link, true, pro.getProxy());
                }
                else
                {
                    responceCodeTemp = con.responseCode(link, true, "");
                }

                if (pro.checkTimeout())
                {
                    int timeoutConvert = stoi(timeoutTempTemp);
                    std::this_thread::sleep_for(std::chrono::milliseconds(timeoutConvert));
                }

                if (pro.checkDebug())
                {
                    if (responceCodeTemp == 200)
                    {
                        prt.printOutput(responceCodeTemp, "", link, true);
                        pro.currect++;
                    }
                    else
                    {
                        prt.printOutput(responceCodeTemp, "", link, false);
                    }
                    if (pro.checkTxt())
                    {
                        if (writeTemp == 1)
                        {
                            out.writeStringTxt(pathTempTemp.c_str(), link, responceCodeTemp);
                        }
                        else
                        {
                            out.writeMode("debug", pathTempTemp.c_str());
                            out.writeStringTxt(pathTempTemp.c_str(), link, responceCodeTemp);
                            writeTemp = 1;
                        }
                    }
                }
                else
                {
                    if (pro.checkCode())
                    {
                        if (responceCodeTemp == pro.getResponceCode())
                        {
                            prt.printOutput(responceCodeTemp, "custom | ", link, true);
                            pro.currect++;
                        }
                    }
                    else
                    {
                        if (responceCodeTemp == 200)
                        {
                            prt.printOutput(responceCodeTemp, "", link, true);
                            pro.currect++;
                        }
                    }
                    if (pro.checkHtml())
                    {
                        std::string tempStr = gen.generateString(5, DICTIONARY);
                        std::string pathHtml = "out/" + nameTempTemp + "/pages/" + tempStr + ".html";
                        con.downloadPage(link, pathHtml.c_str());
                    }

                    if (pro.checkTxt())
                    {
                        if (pro.checkCode())
                        {
                            if (responceCodeTemp == pro.getResponceCode())
                            {
                                if (writeTemp == 1)
                                {
                                    out.writeStringTxt(pathTempTemp.c_str(), link, responceCodeTemp);
                                }
                                else
                                {
                                    if (responceCodeTemp == 200)
                                    {
                                        out.writeMode("normal", pathTempTemp.c_str());
                                    }
                                    if (pro.checkCode())
                                    {
                                        out.writeMode("custom", pathTempTemp.c_str());
                                    }

                                    out.writeStringTxt(pathTempTemp.c_str(), link, responceCodeTemp);
                                    writeTemp = 1;
                                }
                            }
                        }
                        else
                        {
                            if (responceCodeTemp == 200)
                            {
                                if (writeTemp == 1)
                                {
                                    out.writeStringTxt(pathTempTemp.c_str(), link, responceCodeTemp);
                                }
                                else
                                {
                                    out.writeMode("normal", pathTempTemp.c_str());
                                    out.writeStringTxt(pathTempTemp.c_str(), link, responceCodeTemp);
                                    writeTemp = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::seconds>(end - begin);
        prt.printResults(pro.currect);
        if (prt.colorActive){
            std::cout << yellow << bold << "[*] " << reset << "Time to complete the job " << bold << elapsed_ms.count() << reset << " sec\n";
        }
        else {
            std::cout << "[*] Time to complete the job " << elapsed_ms.count() << " sec\n";
        }
        return 0;
    }
}

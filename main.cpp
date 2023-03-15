#include <iostream>
#include "processing.h"
#include <stdio.h>
#include <getopt.h>
#include "output.h"
#include "social.h"

#define VERSION_PROGRAM "0.3.0 by lomaster & oldteam"

output out;
social soc;
processing pro;
connect con;
generate gen;

int main(int argc, char *argv[])
{
    const char *short_options = "n:u:hvbdt::xrlp::";

    const struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {"debug", no_argument, NULL, 'd'},
        {"db", no_argument, NULL, 'b'},
        {"timeout", optional_argument, NULL, 't'},
        {"ru", no_argument, NULL, 'r'},
        {"oX", no_argument, NULL, 'x'},
        {"oL", no_argument, NULL, 'l'},
        {"name", required_argument, NULL, 'n'},
        {"username", required_argument, NULL, 'u'},
        {"proxy", optional_argument, NULL, 'p'},
        {NULL, 0, NULL, 0}};

    if (argc <= 1)
    {
        out.printHelpMenu();
        std::cin.get();
        return true;
    }

    else
    {
        srand(time(nullptr));
        out.initFolders();
        if (soc.initFile())
        {
            int rez;
            int option_index;
            while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
            {
                switch (rez)
                {
                case 'h':
                    out.printHelpMenu();
                    exit(0);
                    break;
                case 'v':
                    std::cout << VERSION_PROGRAM << std::endl;
                    exit(0);
                    break;
                case 'n':
                    pro.nameTemp = optarg;
                    break;
                case 'u':
                    pro.nameTemp = optarg;
                    break;
                case 'd':
                    pro.debugTemp = "1";
                    break;
                case 'b':
                    pro.debugTemp = "1";
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
                        std::cout << "[*] You did not specify a timeout, so the standard timeout is 80ms.\n";
                    }
                    break;
                case 'l':
                    pro.htmlTemp = "1";
                    break;
                 case 'x':
                    pro.txtTemp = "1";
                    break;    
                case 'r':
                    out.printHelpMenuRu();
                    exit(0);
                    break;
                case 'p':
                    pro.proxyTemp = "1";
                    pro.proxyTempTemp = optarg;
                    break;
                case '?':
                default:
                {
                    std::cout << "usage: ./lastn [-h or --help]\n";
                    break;
                }
                }
            }
        }
        std::string nameTempTemp = pro.nameTemp;
        std::string timeout = pro.timeoutTemp;
        std::string path = "out/" + nameTempTemp + "/" + nameTempTemp + ".txt";
        int writeTemp = 0;
        out.initFoldersAdvanced(nameTempTemp);
        std::cout << "[*] Checking nickname " << nameTempTemp << ":\n";
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
                        out.printOutput(temp, "", link, true);
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
                    out.printOutput(temp, "", link, false);
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
                    out.printOutput(temp, "", link, true);
                }
            }
        }
        std::cout << "[*] Search completed with " << pro.currect - 1 << " results\n";

        return 0;
    }
}
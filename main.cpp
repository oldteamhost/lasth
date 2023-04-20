#include <stdio.h>
#include "input.h"
#include <getopt.h>
#include "menu.h"
#include "optargs.h"
#include "output.h"
#include <stdlib.h>
#include <string.h>
#include "codealg.h"
#include <iostream>
#include "parse.h"
#include <chrono>
#include <iomanip>
#include <sstream>

struct opt_args opa;
file_import fi;

void help_menu();
void thanks_list();

const char* run;

int main(int argc, char** argv){

    // for help menu
    run = argv[0];

    // if custom_base
    std::string custom_path_result;

    const char* short_options = "hvT::p:";
    const struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'}, 
        {"proxy", required_argument, 0, 'p'},
        {"timeout", optional_argument, 0, 'T'},
        {"txt", required_argument, 0, 1},
        {"html", required_argument, 0, 2},
        {"db", no_argument, 0, 3},
        {"code", required_argument, 0, 5},
        {"thanks", no_argument, 0, 6},
        {"base", required_argument, 0, 8},
        {0,0,0,0}}; 

        if (argc <= 1){
            help_menu();
            return 0; 
        } 
        // init folders
        init_main_folders();

        int rez;
        int option_index = 0;
        while((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != EOF){
            switch (rez) {
                case 'h':
                    help_menu();
                    return 0;
                    break;
                case 'v':
                    printf("oldteam & %sv\n", version());
                    return 0;
                    break;
                case 'p':
                    opa.proxy_active = 1;
                    opa.proxy = optarg; break;
                case 'T':
                    opa.timeout_active = 1;
                    if (optarg != NULL) 
                        opa.timeout = optarg;
                    else
                        waring_timeout();
                        opa.timeout = "80";
                    break;
                case 1:
                    opa.txt_active = 1;
                    opa.txt_path = optarg;
                    break;
                case 2:
                    opa.html_active = 1;
                    opa.html_path = optarg;
                    break;
                case 3:
                    opa.debug_active = 1;
                    break;
                case 4:
                    opa.debug_active = 1;
                    break;
                case 5:
                {
                    opa.code_active = 1;
                    opa.code_custom = atoi(optarg);
                    break;
                }
                case 6:
                    thanks_list();   
                    return 0;
                    break;
                case 7:
                   opa.fast_active = 1;
                   opa.proxy_active = 0;
                   break; 
                case 8:
                {
                   opa.path_active = 1;
                   std::string optarg_convert = optarg;
                   if (optarg_convert == "max"){
                        custom_path_result = "bases/max.txt";
                   }
                   else if (optarg_convert == "standart"){
                        custom_path_result = "bases/standart.txt";
                   }
                   else if (optarg_convert == "mini"){
                        custom_path_result = "bases/mini.txt";
                   }
                   else {
                        custom_path_result = "bases/" + optarg_convert;
                   }
                   break;
                }
               case '?':
                default:
                    help_menu();
                    return 0;
                    break;
            }
        }

    time_t now = time(NULL);
    struct tm *t = localtime(&now); char datetime[20];

    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", t);
    std::cout << "Starting LastTrench " << version() << " at " << datetime << std::endl;

    check_net();

    if (opa.proxy_active){
        check_proxy(opa.proxy);
    }

    // parse names 
    if (optind < argc){
        opa.target = argv[optind];
    }
    std::vector<std::string> names = split_names(opa.target); // names

    // file init
    std::vector<std::string> words;
    std::vector<std::string> urls;

    if (opa.path_active != 1){
        fi.import_file("bases/standart.txt", words, urls);     
    }
    else {
        fi.import_file(custom_path_result.c_str(), words, urls);     
    }

    int i; // names count
    int success_count = 0; // success count
    std::string result[10000]; // names
    clock_t start, end; // time
    double cpu_time_used; // result time

    // alg code
    start = clock();

    if (opa.proxy_active){
        std::cout << "LasTrench: proxy is active: ( " << opa.proxy << " )\n";
    } 

    if (opa.txt_active && opa.debug_active){
        write_main_info_to_file(opa.txt_path, "\nStarting LastTrench (mode DEBUG) at ");
    }
    else if (opa.txt_active && opa.debug_active != 1){
        write_main_info_to_file(opa.txt_path, "\nStarting LastTrench (mode NORMAL) at ");
    }

    for (i = 0; i < names.size(); i++){

        // for txt save
        if (opa.txt_active){
            std::string name_scan_txt = "\n\tChecking name: " + names[i];
            write_line_to_file(opa.txt_path, name_scan_txt.c_str());
        }

        // main print
        std::cout << "Checking name " << names[i] << ":" << std::endl;
        std::cout << "SERVICE\t\tCODE\tSTATE\tURL\n";

        for(int o = 0; o < urls.size(); o++){

            long code_temp; // standart
            int _code_temp; // fast
            
            result[i] = urls[o] + names[i]; // urls
            
            // timeout            
            if (opa.timeout_active){
                delay_ms(atoi(opa.timeout));
            }

            // code alg
            if (opa.fast_active != 1){
                code_temp = standart_get_responce_code(result[i].c_str(), 0, "");
            }
            if (opa.fast_active != 1 && opa.proxy_active == 1){
                code_temp = standart_get_responce_code(result[i].c_str(), 1, opa.proxy);
            }
            
            std::string result_str_txt = "\t" + words[o] + "\t\t\t" + std::to_string(code_temp) + "\t\t\t" + result[i].c_str();

            if(code_temp == 200){

                // for html save
                if (opa.html_active){
                    std::string html_temp = opa.html_path + names[i] + "__" + words[o] + ".html";
                    download_page_html(result[i].c_str(), html_temp.c_str());
                }
                std::cout << words[o] << "\t" << code_temp << "\tappear\t" << result[i] << std::endl;
                
                // for txt
                if (opa.txt_active)
                    write_line_to_file(opa.txt_path, result_str_txt.c_str());
                
                success_count++;
            }
            
            // custom code anserw
            if (opa.code_active){
                if (code_temp == opa.code_custom){
                    std::cout << words[o] << "\t" << code_temp << "\tappear\t" << result[i] << std::endl;
                }            
            }
            
            // debug print
            if (opa.debug_active){
                // for txt
                if (opa.txt_active)
                    write_line_to_file(opa.txt_path, result_str_txt.c_str());

                if (code_temp == 404){
                    std::cout << words[o] << "\t" << code_temp << "\tfailed\t" << result[i] << std::endl;
                }
                else if (code_temp == 301){
                    std::cout << words[o] << "\t" << code_temp << "\tfilter\t" << result[i] << std::endl;
                }
                else if (code_temp == 302){
                    std::cout << words[o] << "\t" << code_temp << "\tfilter\t" << result[i] << std::endl;
                }
           }
        }
        std::cout << std::endl;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    std::ostringstream oss;
    oss << "LastTrench done: " << success_count << " successful in "
        << std::fixed << std::setprecision(1) << cpu_time_used << "s";

    std::string result_scan = oss.str();
    std::string result_scan_txt = "\n" + result_scan;

    std::cout << result_scan << std::endl;

    // txt save
    if (opa.txt_active){
        write_line_to_file(opa.txt_path, result_scan_txt.c_str());
    }

    return 0;
}

void help_menu(){
    std::cout << "LastTrench: Finding what the person left behind online.\n\n";

    std::cout << "usage: " << run << " [TARGETS (1,2,3) ] [ARGUMENTS]\n\n\n";


    std::cout << "arguments main:\n";
    std::cout << "  -h, --help            Show this help message and exit.\n";
    std::cout << "  -v, --version         Display version information and dependencies.\n";
    std::cout << "  --db, --debug         Saving and outputting even pages that are not working.\n";
    std::cout << "  -T, --timeout<MS>     Set a delay when receiving a page.\n";
    std::cout << "  --thanks              Display all contributors.\n\n";

    std::cout << "arguments save:\n";
    std::cout << "  --txt <FILE>          Save output to txt.\n";
    std::cout << "  --html <FOLDER/>      Save output to html.\n\n";

    std::cout << "arguments user:\n";
    std::cout << "  -p, --proxy <PROXY>   Using proxy server.\n";
    std::cout << "  --base <PATH>         Specify your file with links.\n";
    std::cout << "  --code <CODE>         Specify your correct answer code.\n";
}

void thanks_list(){
    std::cout << "LasTrench v" <<  version() << " lomaster & oldteam\n\n"; 
    std::cout << "Thanks:\n";
    std::cout << "kl1sty on support\n";
}


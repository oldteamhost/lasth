#include "menu.h"
#include <stdio.h>

char* version(void){
    return VERSION;
}

void waring_timeout(void){
    puts("WARING: you did not specify a timeout, so it was set to the default value: 80ms");
}

void file_not_found(const char* file_name){
    printf("ERROR: file %s not found!\n", file_name);
}

void no_net(void){
    puts("ERROR: cannot connect to the Internet!");
}

void no_proxy(void){
    puts("ERROR: cannot connect to the proxy!");
}

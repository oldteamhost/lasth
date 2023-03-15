#pragma once
#include <iostream>
#include "connect.h"
#include "output.h"
#include "social.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include "generate.h"

#define DICTIONARY "_-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

class processing
{
public:
    int currect = 1;

    const char *timeoutTemp = "0";
    const char *timeoutTempTemp;
    const char *nameTemp;
    const char *debugTemp;
    const char *txtTemp;
    const char *htmlTemp;
    const char *proxyTemp;
    const char *proxyTempTemp;
};

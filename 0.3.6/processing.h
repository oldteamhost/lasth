#pragma once
#include <iostream>

#define DICTIONARY "_-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

class processing
{
private:
    int code;

    const char *timeout = "0";
    const char *proxy;
    const char *path;
    const char *name;

    bool timeoutTemp;
    bool pathTemp;
    bool txtTemp;
    bool nameTemp;
    bool htmlTemp;
    bool debugTemp;
    bool codeTemp;
    bool proxyTemp;
    
public:
    int currect = 1;

    void enableTimeout();
    void enablePath();
    void enableTxt();
    void enableHtml();
    void enableName();
    void enableDebug();
    void enableCode();
    void enableProxy();

    bool checkTimeout();
    bool checkPath();
    bool checkTxt();
    bool checkHtml();
    bool checkDebug();
    bool checkCode();
    bool checkProxy();
    bool checkName();

    void setResponceCode(int code);
    void setTimeout(const char* timeout);
    void setPath(const char* path);
    void setName(const char* name);
    void setProxy(const char* proxy);

    int getResponceCode();
    const char* getTimeout();
    const char* getPath();
    const char* getProxy();
    const char* getName();
};

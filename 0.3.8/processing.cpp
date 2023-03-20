#include "includes/processing.h"

void processing::setResponceCode(int code)
{
    this->code = code;
}

void processing::setTimeout(const char *timeout)
{
    this->timeout = timeout;
}

void processing::setPath(const char *path)
{
    this->path = path;
}

void processing::setName(const char *name)
{
    this->name = name;
}

void processing::setProxy(const char *proxy)
{
    this->proxy = proxy;
}

int processing::getResponceCode()
{
    return code;
}

const char *processing::getTimeout()
{
    return timeout;
}

const char *processing::getPath()
{
    return path;
}

const char *processing::getProxy()
{
    return proxy;
}

const char *processing::getName()
{
    return name;
}

void processing::enableTimeout()
{
    timeoutTemp = true;
}

void processing::enablePath()
{
    pathTemp = true;
}

void processing::enableTxt()
{
    txtTemp = true;
}

void processing::enableHtml()
{
    htmlTemp = true;
}

void processing::enableName()
{
    nameTemp = true;
}

void processing::enableDebug()
{
    debugTemp = true;
}

void processing::enableCode()
{
    codeTemp = true;
}

void processing::enableProxy()
{
    proxyTemp = true;
}

bool processing::checkTimeout()
{
    return timeoutTemp;
}

bool processing::checkPath()
{
    return pathTemp;
}

bool processing::checkTxt()
{
    return txtTemp;
}

bool processing::checkHtml()
{
    return htmlTemp;
}

bool processing::checkDebug()
{
    return debugTemp;
}

bool processing::checkCode()
{
    return codeTemp;
}

bool processing::checkProxy()
{
    return proxyTemp;
}

bool processing::checkName()
{
    return nameTemp;
}

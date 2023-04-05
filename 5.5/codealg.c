#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "codealg.h"

size_t clearWrite(void *buffer, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

long standart_get_responce_code(const char *node, int proxy_on, const char *proxy)
{
    CURL *curl = curl_easy_init();
    if (!curl) {
        return 0;
    }

    curl_easy_setopt(curl, CURLOPT_URL, node);
    if (proxy_on == 1) {
        curl_easy_setopt(curl, CURLOPT_PROXY, proxy);
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, clearWrite);
    CURLcode res = curl_easy_perform(curl);

    long response_code = 0;

    if (res == CURLE_OK) {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    }

    curl_easy_cleanup(curl);
    return response_code;
}

void delay_ms(int milliseconds){
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}


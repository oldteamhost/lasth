#include "connect.h"
#include "curl/curl.h"
#include <iostream>

size_t clearWrite(void *buffer, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

long connect::responseCode(const char *link, bool _proxy, const char *proxy)
{
    CURL *curl = curl_easy_init();
    if (curl)
    {
        CURLcode res;
        const char *linkConvert = link;
        curl_easy_setopt(curl, CURLOPT_URL, linkConvert);

        if (_proxy == true)
        {
            curl_easy_setopt(curl, CURLOPT_PROXY, proxy);
        }

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, clearWrite);
        res = curl_easy_perform(curl);

        if (res == CURLE_OK)
        {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            return response_code;
        }
        else
        {
            return 1;
        }

        curl_easy_cleanup(curl);
    }
    return 0;
}

bool connect::downloadPage(const char *link, const char *path)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    const char *url = link;
    const char *outfile = path;

    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(outfile, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "[*] %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return true;
}

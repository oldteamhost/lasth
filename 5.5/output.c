#include <stdio.h>
#include <curl/curl.h>
#include <sys/stat.h> 
#include "output.h"

int download_page_html(const char *node, const char *html_path){
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(html_path, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, node);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK){
            fprintf(stderr, "[*] %s\n", curl_easy_strerror(res));
            return EOF;
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}

int init_data_folder(){
    int temp_data;
    temp_data = mkdir("bases", S_IRUSR | S_IWUSR | S_IXUSR);

    if (temp_data == 0){
        return 0;
    }
    
    return EOF;
}

void init_main_folders(){
    init_data_folder();
}

int write_line_to_file(const char *path, const char *line){
    FILE *file = fopen(path, "a");
    if (file == NULL) {
        printf("LastTrench: error open file\n");
        return EOF;
    }
    fprintf(file, "%s\n", line);
    fclose(file);
    return 0;
}

int write_main_info_to_file(const char* path, const char* line){
    FILE *fp;
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    fp = fopen(path, "a");

    if (fp == NULL) {
        printf("LastTrench: error open file\n");
        return EOF;
    }

    fprintf(fp, "%s %d-%02d-%02d %02d:%02d:%02d\n", line,
        localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
        localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    fclose(fp);
    return 0;
}

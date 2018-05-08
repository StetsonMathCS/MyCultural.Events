#include "curl/curl.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

char url[] = "https://www.stetson.edu/programs/calendar/rss/cultural-credits.rss";

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
}

int main(int argc, char const *argv[])
{

        CURL *curl;
        CURLcode res;
        std::string strContent;
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 30);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strContent);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        FILE* fp = fopen("rss.txt", "w");
        if (fp) {
                fwrite(strContent.c_str(), strContent.length(), 1, fp);

		 fclose(fp);
                system("gedit rss.txt");
        }


        //system("wget https://www.stetson.edu/programs/calendar/rss/cultural-credits.rss >> rss.txt$
        //system("gedit rss.txt");

        return 0;
}


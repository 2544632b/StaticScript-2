#pragma once

#include <curl/curl.h>
#include <iostream>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} _string;

extern "C" _string* get_curl_version();

extern "C" _string* CurlRequestGetRaw(_string* url);
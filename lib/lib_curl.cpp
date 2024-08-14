#include "lib_curl.h"

static size_t _string_get_capacity_with_size(size_t size) {
    if (size == 0) {
        return 16;
    } else if (size < 16) {
        return 32;
    } else if (size < 32) {
        return 48;
    } else {
        return size * 3 / 2;
    }
}

static _string *_string_create_with_capacity(size_t capacity) {
    _string *str = (_string *) malloc(sizeof(_string));
    if (!str) {
        return NULL;
    }
    str->buffer = (char *) calloc(capacity, 1);
    str->capacity = capacity;
    str->size = 0;
    memset(str->buffer, 0, capacity);
    return str;
}

_string *_string_create_1(const char *literal) {
    size_t size = strlen(literal);
    size_t capacity = _string_get_capacity_with_size(size);
    _string *str = _string_create_with_capacity(capacity);
    if (!str) {
        return NULL;
    }
    memcpy(str->buffer, literal, size);
    str->size = size;
    return str;
}

extern "C" _string* get_curl_version() {
    char *ver;
    ver = curl_version();
    if(!ver) {
        return _string_create_1("");
    }
    return _string_create_1(ver);
}

struct MemoryStruct {
  char *memory;
  size_t size;
};

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
  if(ptr == NULL) {
    printf("error: not enough memory\n");
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

extern "C" _string* CurlRequestGetRaw(_string *url) {
    CURL *curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);  
    chunk.size = 0;

    curl_handle = curl_easy_init();

    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url->buffer);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    }

    res = curl_easy_perform(curl_handle);
    if(res != CURLE_OK) {
        return _string_create_1("");
    }

    return _string_create_1(chunk.memory);
}

/*
extern "C" _string* ProxyRequestGetRaw(_string *url, _string *proxy) {

}
*/
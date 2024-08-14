#include "lib_input.h"

const char* input_from_kb() {
    std::string str;
    std::getline(std::cin, str);
    return str.c_str();
}

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

_string *_string_create_0(const char *literal) {
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

extern "C" _string* get_string() {
    return _string_create_0(input_from_kb());
}


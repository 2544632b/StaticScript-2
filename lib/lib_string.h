#pragma once

#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "lib_error.h"

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} _string;

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

static long _string_grow_with_capacity(_string *str, size_t new_capacity) {
    char *new_buffer = (char *)realloc(str->buffer, new_capacity);
    if (!new_buffer) {
        return -1;
    }
    str->buffer = new_buffer;
    str->capacity = new_capacity;
    return 0;
}

static long _string_grow(_string *str) {
    size_t new_capacity = str->capacity < 32 ? str->capacity + 16 : str->capacity * 3 / 2;
    return _string_grow_with_capacity(str, new_capacity);
}

_string *_string_create(const char *literal);

void _string_delete(_string *str);

size_t _string_get_size(_string *str);

long _string_append(_string *dest, _string *src);

long _string_prepend(_string *dest, _string *src);

_string *_string_concat(_string *str1, _string *str2);

_string *_string_slice(_string *str, ssize_t from, ssize_t to);

_string *_string_get_string_character(_string *str, ssize_t pos, _error **error);

long _string_equals(_string *str1, _string *str2);

ssize_t _string_index_of(_string *str, _string *substr);

long _string_trim_left(_string *str);

void _string_trim_right(_string *str);

long _string_trim(_string *str);

long string_size(_string *str);

#pragma once

#include <iostream>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} _string;

extern "C" _string* get_string();
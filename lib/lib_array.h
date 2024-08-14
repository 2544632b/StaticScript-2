#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>
#include "lib_string.h"
#include "lib_error.h"

#define ARRAY_INIT_CAPACITY 16

enum ElementType {
    BooleanType = 1,
    IntegerType = 3,
    FloatType = 5,
    StringType = 7,
    ArrayType = 9
};

typedef struct {
    void *buffer;
    size_t size;
    size_t capacity;
    size_t element_size;
    enum ElementType element_type;
} _array;

static size_t _array_get_capacity_with_size(size_t size) {
    return 1u << (size_t) ceil(log2(size));
}

static void _array_grow(_array *arr, _error **error) {
    size_t new_capacity = arr->capacity * 2;
    void *new_buffer = realloc(arr->buffer, arr->element_size * new_capacity);
    if (!new_buffer) {
        *error = _error_create(REALLOC_FAILED_CODE, REALLOC_FAILED_DESC);
        return;
    }
    arr->buffer = new_buffer;
    arr->capacity = new_capacity;
}

static _array *_array_create(size_t capacity, size_t element_size, enum ElementType element_type, _error **error) {
    _array *arr = (_array *) malloc(sizeof(_array));
    if (!arr) {
        *error = _error_create(MALLOC_FAILED_CODE, MALLOC_FAILED_DESC);
        return NULL;
    }
    arr->buffer = calloc(capacity, element_size);
    if (!arr->buffer) {
        *error = _error_create(CALLOC_FAILED_CODE, CALLOC_FAILED_DESC);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = capacity;
    arr->element_size = element_size;
    arr->element_type = element_type;
    return arr;
}

_array *_array_create_integer_array(_error **error);

_array *_array_create_float_array(_error **error);

_array *_array_create_boolean_array(_error **error);

_array *_array_create_string_array(_error **error);

_array *_array_create_array_array(_error **error);

#define _array_create_array_with_literal(type, element_type) \
    size_t capacity = _array_get_capacity_with_size(size); \
    _array *arr = _array_create(capacity, sizeof(type), element_type, error); \
    if (!arr) { \
        return NULL; \
    } \
    memcpy(arr->buffer, literal_list, arr->element_size * size); \
    arr->size = size; \
    return arr;

_array *_array_create_integer_array_with_literal(long literal_list[], size_t size, _error **error);

_array *_array_create_float_array_with_literal(double literal_list[], size_t size, _error **error);

_array *_array_create_boolean_array_with_literal(bool literal_list[], size_t size, _error **error);

_array *_array_create_string_array_with_literal(_string *literal_list[], size_t size, _error **error);

_array *_array_create_array_array_with_literal(_array *literal_list[], size_t size, _error **error);

void _array_delete(_array *arr);

size_t _array_get_size(_array *arr, _error **error);

bool _array_is_nd_array(_array *arr, _error **error);

bool _array_is_float_array(_array *arr, _error **error);

#define _array_push_detect() \
    if (_array_get_capacity_with_size(arr->size) >= arr->capacity) { \
        _array_grow(arr, error); \
        if (*error != NULL) { \
            return; \
        } \
    } \

#define _array_push(type) \
    type *buffer = (type *) arr->buffer; \
    buffer[arr->size++] = new_element; \


/**
void _array_push_integer(_array *arr, long new_element, _error **error);

void _array_push_float(_array *arr, double new_element, _error **error);

void _array_push_boolean(_array *arr, bool new_element, _error **error);

void _array_push_string(_array *arr, _string *new_element, _error **error);

void _array_push_array(_array *arr, _array *new_element, _error **error);
*/


void push_back_integer(_array *arr, long new_element);

void push_back_float(_array *arr, double new_element);

void push_back_string(_array *arr, _string *new_element);


#define _array_pop_detect(zero_value) \
    if (arr->size == 0) { \
        *error = _error_create(EMPTY_ARRAY_POP_CODE, EMPTY_ARRAY_POP_DESC); \
        return zero_value; \
    }

#define _array_pop(type) \
    type *buffer = (type *) arr->buffer; \
    return buffer[--arr->size];

/*
long _array_pop_integer(_array *arr, _error **error);

double _array_pop_float(_array *arr, _error **error);

bool _array_pop_boolean(_array *arr, _error **error);

_string *_array_pop_string(_array *arr, _error **error);

_array *_array_pop_array(_array *arr, _error **error);
*/

#define _array_get_detect(zero_value) \
    if (index >= arr->size) {           \
        *error = _error_create(ARRAY_INDEX_GE_SIZE_CODE, ARRAY_INDEX_GE_SIZE_DESC); \
        return zero_value; \
    }

#define _array_get(type) \
    type *buffer = (type *) arr->buffer; \
    return buffer[index];

long _array_get_integer(_array *arr, size_t index, _error **error);

double _array_get_float(_array *arr, size_t index, _error **error);

bool _array_get_boolean(_array *arr, size_t index, _error **error);

_string *_array_get_string(_array *arr, size_t index, _error **error);

_array *_array_get_array(_array *arr, size_t index, _error **error);

#define _array_set_detect() \
    if (index >= arr->size) { \
        *error = _error_create(ARRAY_INDEX_GE_SIZE_CODE, ARRAY_INDEX_GE_SIZE_DESC); \
        return; \
    }

#define _array_set(type) \
    type *buffer = (type *)arr->buffer; \
    buffer[index] = element;

void _array_set_integer(_array *arr, size_t index, long element, _error **error);

void _array_set_float(_array *arr, size_t index, double element, _error **error);

void _array_set_boolean(_array *arr, size_t index, bool element, _error **error);

void _array_set_string(_array *arr, size_t index, _string *element, _error **error);

void _array_set_array(_array *arr, size_t index, _array *element, _error **error);

_array *_array_slice(_array *arr, ssize_t from, ssize_t to, _error **error);

long array_length(_array *arr);

_array *string_to_array(_string *str);

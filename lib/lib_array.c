#include "lib_array.h"

_array *_array_create_integer_array(_error **error) {
    return _array_create(ARRAY_INIT_CAPACITY, sizeof(long), IntegerType, error);
}

_array *_array_create_float_array(_error **error) {
    return _array_create(ARRAY_INIT_CAPACITY, sizeof(double), FloatType, error);
}

_array *_array_create_boolean_array(_error **error) {
    return _array_create(ARRAY_INIT_CAPACITY, sizeof(bool), BooleanType, error);
}

_array *_array_create_string_array(_error **error) {
    return _array_create(ARRAY_INIT_CAPACITY, sizeof(_string *), StringType, error);
}

_array *_array_create_array_array(_error **error) {
    _array *arr = _array_create(ARRAY_INIT_CAPACITY, sizeof(_array *), ArrayType, error);
    if (!arr) {
        return NULL;
    }
    return arr;
}

_array *_array_create_integer_array_with_literal(long literal_list[], size_t size, _error **error) {
    _array_create_array_with_literal(long, IntegerType)
}

_array *_array_create_float_array_with_literal(double literal_list[], size_t size, _error **error) {
    _array_create_array_with_literal(double, FloatType)
}

_array *_array_create_boolean_array_with_literal(bool literal_list[], size_t size, _error **error) {
    _array_create_array_with_literal(bool, BooleanType)
}

_array *_array_create_string_array_with_literal(_string *literal_list[], size_t size, _error **error) {
    _array_create_array_with_literal(_string *, StringType)
}

_array *_array_create_array_array_with_literal(_array *literal_list[], size_t size, _error **error) {
    _array_create_array_with_literal(_array *, ArrayType)
}

void _array_delete(_array *arr) {
    if (arr != NULL) {
        if (arr->buffer != NULL) {
            free(arr->buffer);
        }
        free(arr);
    }
}

size_t _array_get_size(_array *arr, _error **error) {
    if (!arr) {
        *error = _error_create(NULL_ARRAY_PTR_CODE, NULL_ARRAY_PTR_DESC);
        return 0;
    }
    return arr->size;
}

bool _array_is_nd_array(_array *arr, _error **error) {
    if (!arr) {
        *error = _error_create(NULL_ARRAY_PTR_CODE, NULL_ARRAY_PTR_DESC);
        return false;
    }
    return arr->element_type == ArrayType;
}

bool _array_is_float_array(_array *arr, _error **error) {
    if (!arr) {
        *error = _error_create(NULL_ARRAY_PTR_CODE, NULL_ARRAY_PTR_DESC);
        return false;
    }
    return arr->element_type == FloatType;
}

void _array_push_integer(_array *arr, long new_element, _error **error) {
    _array_push_detect()
    _array_push(long)
}

void _array_push_float(_array *arr, double new_element, _error **error) {
    _array_push_detect()
    _array_push(double)
}

void _array_push_boolean(_array *arr, bool new_element, _error **error) {
    _array_push_detect()
    _array_push(bool)
}

void _array_push_string(_array *arr, _string *new_element, _error **error) {
    _array_push_detect()
    _array_push(_string *)
}

void _array_push_array(_array *arr, _array *new_element, _error **error) {
    _array_push_detect()
    _array_push(_array *)
}

/* User func start */
void push_back_integer(_array *arr, long new_element) {
    _error *err = _error_create(1200, "failed");
    _array_push_integer(arr, new_element, &err);
}

void push_back_float(_array *arr, double new_element) {
    _error *err = _error_create(1200, "failed");
    _array_push_float(arr, new_element, &err);
}

void push_back_string(_array *arr, _string *new_element) {
    _error *err = _error_create(1200, "failed");
    _array_push_string(arr, new_element, &err);
}
/* User func end */

long _array_pop_integer(_array *arr, _error **error) {
    _array_pop_detect(0)
    _array_pop(long)
}

double _array_pop_float(_array *arr, _error **error) {
    _array_pop_detect(0)
    _array_pop(double)
}

bool _array_pop_boolean(_array *arr, _error **error) {
    _array_pop_detect(false)
    _array_pop(bool)
}

_string *_array_pop_string(_array *arr, _error **error) {
    _array_pop_detect(NULL)
    _array_pop(_string *)
}

_array *_array_pop_array(_array *arr, _error **error) {
    _array_pop_detect(NULL)
    _array_pop(_array *)
}

long _array_get_integer(_array *arr, size_t index, _error **error) {
    _array_get_detect(0)
    _array_get(long)
}

double _array_get_float(_array *arr, size_t index, _error **error) {
    _array_get_detect(0)
    _array_get(double)
}

bool _array_get_boolean(_array *arr, size_t index, _error **error) {
    _array_get_detect(false)
    _array_get(bool)
}

_string *_array_get_string(_array *arr, size_t index, _error **error) {
    _array_get_detect(NULL)
    _array_get(_string *)
}

_array *_array_get_array(_array *arr, size_t index, _error **error) {
    _array_get_detect(NULL)
    _array_get(_array *)
}

void _array_set_integer(_array *arr, size_t index, long element, _error **error) {
    _array_set_detect()
    _array_set(long)
}

void _array_set_float(_array *arr, size_t index, double element, _error **error) {
    _array_set_detect()
    _array_set(double)
}

void _array_set_boolean(_array *arr, size_t index, bool element, _error **error) {
    _array_set_detect()
    _array_set(bool)
}

void _array_set_string(_array *arr, size_t index, _string *element, _error **error) {
    _array_set_detect()
    _array_set(_string *)
}

void _array_set_array(_array *arr, size_t index, _array *element, _error **error) {
    _array_set_detect()
    _array_set(_array *)
}


_array *_array_slice(_array *arr, ssize_t from, ssize_t to, _error **error) {
    if (from < 0) {
        from = arr->size + from;
    }
    if (to < 0) {
        to = arr->size + to;
    }
    if (to < from) {
        *error = _error_create(ARRAY_SLICE_TO_LT_FROM_CODE, ARRAY_SLICE_TO_LT_FROM_DESC);
        return NULL;
    }
    size_t slice_size = to - from;
    size_t new_capacity = _array_get_capacity_with_size(slice_size);
    _array *new_arr = _array_create(new_capacity, arr->element_size, arr->element_type, error);
    if (!new_arr) {
        return NULL;
    }
    memcpy(new_arr->buffer, arr->buffer + from * arr->element_size, slice_size * arr->element_size);
    new_arr->size = slice_size;
    return new_arr;
}

long array_length(_array *arr) {
    _error *err;
    return (long)(_array_get_size(arr, &err));
}

_array *string_to_array(_string *str) {
    _error *err = _error_create(100001, "malloc error");
    _array *arr = _array_create_string_array(&err);
    
    ssize_t len = _string_get_size(str);
    for(int i = 0; i < len; i++) {
        char character[2] = {str->buffer[i], '\0'};
        _string *temp = _string_create(character);
        _array_push_string(arr, temp, &err);    // Problem here
    }

    return arr;
}

#include "lib_string.h"

_string *_string_create(const char *literal) {
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

void _string_delete(_string *str) {
    free(str->buffer);
    free(str);
}

size_t _string_get_size(_string *str) {
    return str->size;
}

/* User func start */
long string_size(_string *str) {
    return _string_get_size(str);
}
/* User func end */

long _string_append(_string *dest, _string *src) {
    size_t needed_size = dest->size + src->size;
    size_t needed_capacity = _string_get_capacity_with_size(needed_size);
    if (dest->capacity < needed_capacity) {
        if (_string_grow_with_capacity(dest, needed_capacity) == -1) {
            return -1;
        }
    }
    strncat(dest->buffer, src->buffer, src->size);
    dest->size = needed_size;
    return 0;
}

long _string_prepend(_string *dest, _string *src) {
    size_t needed_size = dest->size + src->size;
    size_t needed_capacity = _string_get_capacity_with_size(needed_size);
    if (dest->capacity < needed_capacity) {
        if (_string_grow_with_capacity(dest, needed_capacity) == -1) {
            return -1;
        }
    }
    memmove(dest->buffer + src->size, dest->buffer, src->size + 1);
    memcpy(dest->buffer, src->buffer, src->size);
    dest->size = needed_size;
    return 0;
}

_string *_string_concat(_string *str1, _string *str2) {
    size_t size = str1->size + str2->size;
    size_t capacity = _string_get_capacity_with_size(size);
    _string *str = _string_create_with_capacity(capacity);
    memcpy(str->buffer, str1->buffer, str1->size);
    memcpy(str->buffer + str1->size, str2->buffer, str2->size);
    str->size = size;
    return str;
}

_string *_string_slice(_string *str, ssize_t from, ssize_t to) {
    if (from < 0) {
        from = str->size + from;
    }
    if (to < 0) {
        to = str->size + to;
    }
    if (to < from) {
        return NULL;
    }
    size_t slice_size = to - from;
    size_t new_capacity = _string_get_capacity_with_size(slice_size);
    _string *new_str = _string_create_with_capacity(new_capacity);
    memcpy(new_str->buffer, str->buffer + from, slice_size);
    new_str->size = slice_size;
    return new_str;
}

_string *_string_get_string_character(_string *str, ssize_t pos, _error **error) {
    ssize_t len = _string_get_size(str);
    
    char character[2] = {str->buffer[pos], '\0'};
    if(pos > len || pos < 0) {
        ss_exit_if_error(*error);
    }
    _string *temp = _string_create(character);

    return temp;
}

long _string_equals(_string *str1, _string *str2) {
    if (str1->size != str2->size) {
        return -1;
    }
    return strncmp(str1->buffer, str2->buffer, str1->size);
}

ssize_t _string_index_of(_string *str, _string *substr) {
    char *sub = strstr(str->buffer, substr->buffer);
    if (!sub) {
        return -1;
    }
    return sub - str->buffer;
}

long _string_trim_left(_string *str) {
    size_t i = 0;
    while (isspace(str->buffer[i])) {
        i += 1;
    }
    char *new_buffer = (char *) calloc(str->capacity, 1);
    if (!new_buffer) {
        return -1;
    }
    memset(new_buffer, 0, str->capacity);
    memcpy(new_buffer, str->buffer + i, str->size - i);
    free(str->buffer);
    str->buffer = new_buffer;
    str->size -= i;
    return 0;
}

void _string_trim_right(_string *str) {
    ssize_t i = str->size - 1;
    while (i >= 0 && isspace(str->buffer[i])) {
        str->buffer[i] = 0;
        i -= 1;
    }
    str->size = i + 1;
}

long _string_trim(_string *str) {
    _string_trim_right(str);
    return _string_trim_left(str);
}
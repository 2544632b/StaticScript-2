#include "lib_io.h"

_string *integer2string(long number) {
    size_t capacity = _string_get_capacity_with_size(20);
    _string *str = _string_create_with_capacity(capacity);
    snprintf(str->buffer, 20, "%ld", number);
    str->size = strlen(str->buffer);
    return str;
}

_string *integer2ascii(long number) {
    size_t capacity = _string_get_capacity_with_size(20);
    _string *str = _string_create_with_capacity(capacity);
    snprintf(str->buffer, 20, "%ld", (number - 'a'));
    return str;
}

_string *float2string(double number) {
    size_t capacity = _string_get_capacity_with_size(20);
    _string *str = _string_create_with_capacity(capacity);
    snprintf(str->buffer, 20, "%lf", number);
    str->size = strlen(str->buffer);
    return str;
}

long string2integer(_string *str) {
    return strtol(str->buffer, NULL, 10);
}

double string2float(_string *str) {
    return strtod(str->buffer, NULL);
}

void print_number(long number) {
    printf("%ld", number);
}

void print_number_ln(long number) {
    printf("%ld\n", number);
}

void print_float(double number) {
    printf("%f", number);
}

void print_float_ln(double number) {
    printf("%f\n", number);
}

void print_string(_string *str) {
    printf("%s", str->buffer);
}

void print_string_ln(_string *str) {
    printf("%s\n", str->buffer);
}

void print_ln() {
    printf("\n");
}
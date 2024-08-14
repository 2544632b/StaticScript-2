#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "lib_string.h"

_string *integer2string(long number);

_string *integer2ascii(long number);

_string *float2string(double number);

long string2integer(_string *str);

double string2float(_string *str);

void print_number(long number);

void print_number_ln(long number);

void print_float(double number);

void print_float_ln(double number);

void print_string(_string *str);

void print_string_ln(_string *str);

void print_ln();
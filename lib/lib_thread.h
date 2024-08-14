#pragma once

#include <iostream>
// #include <thread>
#include <dlfcn.h>
#include <pthread.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} _string;

extern "C" _opaque_pthread_t* CreateThread(_string *funcKey);

extern "C" void JoinThread(_opaque_pthread_t* t);

extern "C" void DetachThread(_opaque_pthread_t* t);

extern "C" void ExitThread();
#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <map>
#include "lib_loop.h"

typedef struct _string {
    char *buffer;
    size_t size;
    size_t capacity;
} _string;

#define DEFAULT_BACKLOG 128

_string* response;

typedef struct _socket {
    uv_tcp_t inst;
} _socket;

extern "C" _socket* CreateSocket();

extern "C" void SetSocketMessage(_socket* socket, _string* message);

extern "C" void Listen(_socket* socket, _string* address, long port);
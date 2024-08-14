#include "lib_socket.h"

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

_string *_string_create_2(const char *literal) {
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

void alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t *buf) {
  buf->len = suggested_size;
  buf->base = static_cast<char *>(malloc(suggested_size));
}

void onSocketFinally(uv_write_t* req, int status) {
    if (status) {
        printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: -510\n\tdescription: %s\n""\033[0m", uv_strerror(status));
    }
    free(req);
}

void onSocketRead(uv_stream_t* client, ssize_t nread, const uv_buf_t *buf) {
    if (nread > 0) {
        _string *str = _string_create_2(buf->base); // str->req, res->res
        _string *res = response;

        uv_write_t *uvreq = new uv_write_t();
        uv_buf_t uvBuf = uv_buf_init(res->buffer, strlen(res->buffer));
        uv_write(uvreq, client, &uvBuf, 1, onSocketFinally);

        return;
    }
    if (nread < 0) {
        if (nread != UV_EOF) {
            printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: -510\n\tdescription: %s\n""\033[0m", uv_err_name(nread));
        }
    }

    free(buf->base);
}

void onConnection(uv_stream_t* server, int status) {
    if (status < 0) {
        printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: -509\n\tdescription: %s\n""\033[0m", uv_strerror(status));
        return;
    }

    uv_tcp_t *client = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, client);

    if (uv_accept(server, (uv_stream_t*)client) == 0) {
        uv_read_start((uv_stream_t*)client, alloc_buffer, onSocketRead);
    } else {
        uv_close((uv_handle_t*)client, NULL);
    }
}

extern "C" _socket* CreateSocket() {
    loop = uv_default_loop();

    _socket *socket = new struct _socket();
    uv_tcp_init(loop, &socket->inst);

    return socket;
}

extern "C" void SetSocketMessage(_socket* socket, _string* message) {
    response = message;
}

extern "C" void Listen(_socket* socket, _string* address, long port) {
    struct sockaddr_in addr;
    uv_ip4_addr(address->buffer, port, &addr);
    uv_tcp_bind(&socket->inst, (const struct sockaddr *) &addr, 0);
    int r = uv_listen((uv_stream_t*)&socket->inst, DEFAULT_BACKLOG, onConnection);

    if (r) {
        printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: -501\n\tdescription: Can not bind the socket\n""\033[0m");
        abort();
    }
    uv_run(loop, UV_RUN_DEFAULT);
}
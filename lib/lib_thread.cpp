#include "lib_thread.h"

void* TempCreate(void* symbol) {
    void (*func)() = (void (*)())dlsym(RTLD_DEFAULT, (char*)symbol);
    if(func == nullptr) {
        printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: -31\n\tdescription: Create thread failed!\n""\033[0m");
        abort();
    }
    func();
}

extern "C" _opaque_pthread_t* CreateThread(_string* funcKey) {
    pthread_t pt;
    pthread_create(&pt, NULL, TempCreate, (void*)funcKey->buffer);
    return (_opaque_pthread_t*)pt;
}

extern "C" void ThreadJoin(_opaque_pthread_t* t) {
    pthread_join((pthread_t)t, NULL);
}

extern "C" void DetachThread(_opaque_pthread_t* t) {
    pthread_detach((pthread_t)t);
}

extern "C" void ThreadExit() {
    pthread_exit(NULL);
}
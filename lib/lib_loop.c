#include "lib_loop.h"

void DefaultLoop() {
    loop = uv_default_loop();
}

void LoopSetup() {
    if (uv_run(loop, UV_RUN_DEFAULT) < 0) {
        printf("\033[0;31m""[StaticScript Runtime Error]:\n\tcode: -371\n\tdescription: Unable to start a loopping\n""\033[0m");
    }
}
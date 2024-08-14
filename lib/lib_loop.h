#pragma once

#include <uv.h>

static uv_loop_t *loop;

void DefaultLoop();

void LoopSetup();
#pragma once

#include <stdint.h>

#include <freefall/struct/method.h>

typedef struct jvm_frame_t {
    uint32_t* locals;
    uint32_t* stack;
    int sp;
    const jvm_code_attrib_t* code;
    uint32_t pc;
} jvm_frame_t;

typedef struct jvm_callstack_t {
    jvm_frame_t* frames;
    int depth;
    int cap;
} jvm_callstack_t;


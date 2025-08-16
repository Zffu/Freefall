#pragma once

#include <stdint.h>

typedef struct jvm_code_attrib_t {
    uint16_t max_stack_sz;
    uint16_t max_local_sz;

    uint32_t code_len;
    uint8_t* code;
} jvm_code_attrib_t;

typedef struct jvm_method_info_t {
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;

    jvm_code_attrib_t code;
} jvm_method_info_t;
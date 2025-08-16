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

typedef struct jvm_resolved_method_t {
    char* class_name;
    char* method_name;
    char* descriptor;
    const jvm_method_info_t* method;
} jvm_resolved_method_t;    

/**
 * @name jvm_read_code_attrib
 * 
 * Reads the code attribute struct from the given bytes
 * 
 * @param p the bytes
 * @param out the out pointer
 */
void jvm_read_code_attrib(int8_t** p, jvm_code_attrib_t* out);

/**
 * Definitions for Java CP entries
 */

#include <stdint.h>

#pragma once

typedef struct cp_as_class {
    uint16_t name_ind;
} cp_as_class;

typedef struct cp_as_method {
    uint16_t name_ind;
    uint16_t name_and_type_ind;
} cp_as_method;

typedef struct cp_as_nameandmethod {
    uint16_t name_ind;
    uint16_t descriptor_ind;
} cp_as_nameandmethod;

typedef struct cp_as_string {
    uint16_t string_ind;
} cp_as_string;

typedef struct cp_as_int {
    int32_t bytes;
} cp_as_int;

typedef struct cp_as_utf8 {
    uint16_t length;
    uint8_t* bytes;
} cp_as_utf8;

typedef struct jvm_cp_entry_t {
    uint8_t cp_tag;

    // TODO: check if this cannot be improved to use a lesser size than the max
    union {
        cp_as_class as_class;
        cp_as_method as_method;
        cp_as_nameandmethod as_nameandmethod;
        cp_as_string as_string;
        cp_as_int as_int;
        cp_as_utf8 as_utf8;
    };
} jvm_cp_entry_t;
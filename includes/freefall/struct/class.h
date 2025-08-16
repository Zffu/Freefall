#pragma once

#include <stdint.h>
#include <stdio.h>

#include <freefall/cp/cpentry.h>
#include <freefall/struct/method.h>

typedef struct jvm_class_file_t {
    uint8_t* buff;
    size_t len;

    uint16_t jdk_minor;
    uint16_t jdk_major;

    uint16_t cp_entry_count;
    jvm_cp_entry_t* cp_entries;

    uint16_t access_flags;
    uint16_t this_class;
    uint16_t superclass;

    uint16_t interfaces_count;
    uint16_t field_count;
    uint16_t method_count;

    jvm_method_info_t* methods;

} jvm_class_file_t;
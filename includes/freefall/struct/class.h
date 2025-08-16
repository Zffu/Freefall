#pragma once

#include <stdint.h>
#include <stdio.h>

#include <freefall/cp/cpentry.h>
#include <freefall/struct/method.h>

#define JVM_CLASS_MAGIC 0xCAFEBABE

typedef struct jvm_class_file_t {
    //uint8_t* buff;
    //size_t len;

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

/**
 * @name jvm_read_class
 * 
 * Reads the class file.
 * 
 * @param path the file path
 * @param out the out pointer of the class file
 */
void jvm_read_class(char* path, jvm_class_file_t* out);

jvm_method_info_t* jvm_find_method(jvm_class_file_t* file, const char* name, const char* desc);

jvm_method_info_t* jvm_find_method_in_clazz(jvm_class_file_t* file, uint16_t methodref_ind, jvm_resolved_method_t* out);
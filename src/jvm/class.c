#include <freefall/struct/class.h>

#include <freefall/utils/types.h>

#include <stdio.h>
#include <string.h>

void jvm_read_class(char* path, jvm_class_file_t* out) {
    FILE* fptr = fopen(path, "rb");
    if(!fptr) return;

    uint8_t* ptr = fptr->_IO_read_ptr;

    if(INT32(ptr) != JVM_CLASS_MAGIC) {
        return;
    }

    ptr += 4;

    out->jdk_minor = READ_INT_16(ptr);
    out->jdk_major = READ_INT_16(ptr);

    out->cp_entry_count = READ_INT_16(ptr);
    out->cp_entries = malloc(sizeof(jvm_cp_entry_t) * out->cp_entry_count);

    for(uint16_t i = 1; i < out->cp_entry_count; ++i) {
        uint8_t tag = *++ptr;
        out->cp_entries[i].cp_tag = tag;

        switch(tag) {
            case CLASS:
                out->cp_entries[i].as_class.name_ind = READ_INT_16(ptr);
                break;
            case STRING:
                out->cp_entries[i].as_string.string_ind = READ_INT_16(ptr);
                break;
            case INT:
                out->cp_entries[i].as_int.bytes = READ_INT_32(ptr);
                break;
            case METHOD_REFERENCE:
                out->cp_entries[i].as_methodref.name_ind = READ_INT_16(ptr);
                out->cp_entries[i].as_methodref.name_and_type_ind = READ_INT_16(ptr);
                break;
            case NAME_AND_TYPE:
                out->cp_entries[i].as_nameandmethod.name_ind = READ_INT_16(ptr);
                out->cp_entries[i].as_nameandmethod.descriptor_ind = READ_INT_16(ptr);
                break;
            case UTF8:
                uint16_t len = READ_INT_16(ptr);
                char* s = malloc(len + 1);

                memcpy(s, ptr, len);
                s[len] = '\0';
                ptr += len;

                out->cp_entries[i].as_utf8.length = len;
                out->cp_entries[i].as_utf8.bytes = s;
                break;
            case LONG:
            case DOUBLE:
                ptr += 8;
                ++i;
                break;
            default:
                printf("BAD CP tag %u at #%u\n", tag, i);
                
        }
    }

    out->method_count = READ_INT_16(ptr);
    out->methods = malloc(sizeof(jvm_method_info_t) * out->method_count);

    for(uint16_t i = 0; i < out->method_count; ++i) {
        jvm_method_info_t* info = &out->methods[i];
        info->access_flags = READ_INT_16(ptr);
        info->name_index = READ_INT_16(ptr);
        info->descriptor_index = READ_INT_16(ptr);

        uint16_t attrc = READ_INT_16(ptr);
    
        for(uint16_t j = 0; j < attrc; ++j) {
            uint16_t aname = READ_INT_16(ptr);
            uint32_t alen = READ_INT_32(ptr);

            char* name;
            CP_ENTRY_TO_UTF8(out, aname, name);

            if(strcmp(name, "Code") == 0) {
                uint8_t* q = ptr;
                jvm_read_code_attrib(&q, &info->code);
                ptr = q;
            }
            else {
                ptr += alen;
            }
        }
    }

    uint16_t class_attrib = READ_INT_16(ptr);
    for(uint16_t i = 0; i < class_attrib; ++i) {
        ptr += 2;
        uint32_t alen = READ_INT_32(ptr);
        ptr += alen;
    }    
}
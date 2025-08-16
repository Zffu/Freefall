#include <freefall/struct/method.h>
#include <freefall/utils/types.h>

#include <stdlib.h>
#include <string.h>

void jvm_read_code_attrib(int8_t** p, jvm_code_attrib_t* out) {
    uint16_t max_stack = READ_INT_16(*p);
    uint16_t max_locals = READ_INT_16(*p);
    uint32_t code_len = READ_INT_32(*p);

    uint8_t* code = (uint8_t*) malloc(code_len);
    memcpy(code, *p, code_len);

    uint16_t ex_len = READ_INT_16(*p);
    *p += ex_len * 8;

    uint16_t attrib_c = READ_INT_16(*p);

    for(uint16_t i = 0; i < attrib_c; ++i) {
        uint16_t name_ind = READ_INT_16(*p);
        uint32_t a_len = READ_INT_32(*p);

        *p += a_len;
    }

    out->max_stack_sz = max_stack;
    out->max_local_sz = max_locals;
    out->code_len = code_len;
    out->code = code;
}
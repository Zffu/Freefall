/**
 * Type utilities for Freefall
 */

#include <stdint.h>

#define INT_16(p) (uint16_t)(p[0]<<8 | p[1])
#define INT_32(p) (uint32_t)(p[0]<<24 | p[1]<<16 | p[2]<<8 | p[3]);

#define READ_INT_16(p) INT_16(p); \
    p += 2;

#define READ_INT_32(p) INT_32(p); \
    p += 4;
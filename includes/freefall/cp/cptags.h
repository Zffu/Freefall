/**
 * Collection of native Java tags.
 */

#pragma once

typedef enum cp_tags {
    UTF8 = 1,
    INT = 3,
    FLOAT = 4,
    LONG = 5,
    DOUBLE = 6,
    CLASS = 7,
    STRING = 8,
    FIELD_REFERENCE = 9,
    METHOD_REFERENCE = 10,
    INTERFACE_METHOD_REFERENCE = 11,
    NAME_AND_TYPE= 12,
    METHOD_HANDLE = 15,
    METHOD_TYPE = 16,
    DYNAMIC = 17,
    INVOKE_DYNAMIC = 18,
    MODULE = 19,
    PACKAGE = 20
} cp_tags;
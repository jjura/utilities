#ifndef COMMON_H
#define COMMON_H

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define error(message, ...) {     \
    printf("Error: " message "\n", __VA_ARGS__); \
    exit(EXIT_FAILURE);           \
}

typedef char char_t;
typedef signed int int32_t;
typedef void void_t;

#endif

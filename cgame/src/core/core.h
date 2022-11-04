#pragma once

#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef unsigned int render_id;

#define true 1
#define false 0

#define bool8 unsigned char
#define bool32 unsigned int

#define nullptr (void*)0

#define LOG_DEBUG(...) {													    \
	printf("[DEBUG]");                                                          \
    printf(__VA_ARGS__);                                                        \
	printf("\n");															    \
}

#define LOG_TRACE(...) {													    \
	printf("[TRACE]");                                                          \
    printf(__VA_ARGS__);     												    \
	printf("\n");															    \
}

#define LOG_INFO(...) {														    \
	printf("[INFO]");                                                           \
    printf(__VA_ARGS__);     												    \
	printf("\n");															    \
}

#define LOG_WARN(...) {														    \
	printf("[WARN]");                                                           \
    printf(__VA_ARGS__);     											        \
	printf("\n");															    \
}

#define LOG_ERROR(...) {													    \
	printf("[ERROR]");                                                          \
    printf(__VA_ARGS__);     												    \
	printf("\n");															    \
}

#define LOG_CRITICAL(msg, ...) {											    \
    printf("[CRITICAL]");                                                       \
    printf(__VA_ARGS__);     											        \
	printf("\n");															    \
}
#define ASSERT(cond)                                                            \
    {                                                                           \
        if (cond) {                                                             \
        } else {                                                                \
            printf("Assertion failed: '%s' in file '%s' on line %i.",           \
                   #cond, __FILE__, __LINE__);                                  \
            __debugbreak();                                                     \
        }                                                                       \
    }

#define ASSERT_MSG(cond, ...)                                                   \
    {                                                                           \
        if (cond) {                                                             \
        } else {                                                                \
            printf("Assertion failed: '%s' in file '%s' on line %i.\n",         \
                   #cond, __FILE__, __LINE__);                                  \
            printf("'");                                                        \
            printf(__VA_ARGS__);                                                \
            printf("'\n");                                                      \
            __debugbreak();                                                     \
        }                                                                       \
    }
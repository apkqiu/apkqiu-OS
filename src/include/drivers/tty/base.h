#pragma once
#include <stddef.h>
#include <stdint.h>
typedef struct TTY
{
    uint8_t driver_type;
    void (*putchar)(const struct TTY *tty, const char c);
    uint8_t extra_data[32];
} TTY;

int ttyprintf(TTY *tty, const char *format, ...);

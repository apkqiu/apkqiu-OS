#pragma once
#include <stddef.h>
#include <stdint.h>
typedef struct Display
{
    uint8_t driver_type;

    uint8_t display_type;

    void *buffer;
    size_t buffer_width;
    size_t buffer_height;

    union
    {
        void (*text)(const struct Display *display, size_t row, size_t col, char text, uint8_t color);
        void (*pixel)(const struct Display *display, size_t x, size_t y, uint64_t color);
    } set;
} Display;

#define DISPLAY_TYPE_TEXT 0x01
#define DISPLAY_TYPE_GRAPHICS 0x02
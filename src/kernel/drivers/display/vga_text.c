#include "vga_text.h"

void set_char(const Display *display, size_t row, size_t col, char text, uint8_t color){
    struct{
        char text;
        uint8_t color;
    } *buffer = display->buffer;
    buffer[row*display->buffer_width+col].text = text;
    buffer[row*display->buffer_width+col].color = color;
}

void setup_display_vga_text(Display *display){
    display->buffer = (void *)0xB8000;
    display->buffer_width = 80;
    display->buffer_height = 25;

    display->driver_type = VGA_TEXT_DISPLAY_DRIVER_TYPE;
    display->display_type = DISPLAY_TYPE_TEXT;

    display->set.text = set_char;
}

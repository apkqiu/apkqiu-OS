#include <stdint.h>
#include "string.h"
#include "drivers/tty/screen_text.h"
struct tty_exdata{
    Display *display;
    int offset;
};
void screen_putchar(const struct TTY *tty, const char c){
    struct tty_exdata*data = (void*)&tty->extra_data;
    if(c=='\n')
        data->offset = (data->offset / data->display->buffer_width + 1) * data->display->buffer_width;
    else
        data->display->set.text(data->display, 0, data->offset++, c, 0x07);
    if(data->offset >= data->display->buffer_height * data->display->buffer_width){
        memcpy(data->display->buffer, data->display->buffer+data->display->buffer_width*2, data->display->buffer_width*2*(data->display->buffer_height-1));
        data->offset = data->display->buffer_width*(data->display->buffer_height-1);
    }
}
void setup_tty_screen_text(TTY* tty, Display* display){
    struct tty_exdata*data = (void*)&tty->extra_data;
    data->display = display;
    data->offset = 0;
    tty->putchar = screen_putchar;
}

#define SCREEN_TEXT_TTY_DRIVER_TYPE     0x11
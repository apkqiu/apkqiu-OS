#include <stdarg.h>
#include "drivers/tty/base.h"
#include "stdio.h"
void tty_out(char character, void *arg)
{
    ((TTY*)arg)->putchar(arg, character);
}

int ttyprintf(TTY *tty, const char *format, ...)
{
    va_list va;
    va_start(va, format);
    const int ret = vfcprintf(tty_out, tty, format, va);
    va_end(va);
    return ret;
}
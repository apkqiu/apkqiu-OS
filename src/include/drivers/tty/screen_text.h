#pragma once
#include <stdint.h>
#include "drivers/tty/base.h"
#include "drivers/display/base.h"
void setup_tty_screen_text(TTY*, Display*);

#define SCREEN_TEXT_TTY_DRIVER_TYPE     0x11
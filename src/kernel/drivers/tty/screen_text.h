#pragma once
#include <stdint.h>
#include "base.h"
#include "../display/base.h"
void setup_tty_screen_text(TTY*, Display*);

#define SCREEN_TEXT_TTY_DRIVER_TYPE     0x11
// include/drivers/keyboard.h
#pragma once
#include <stdint.h>

// 初始化键盘（清空状态，使能 IRQ1）
void keyboard_init(void);

// 处理从队列中取出的扫描码（由主循环调用）
char keyboard_process_scancode(uint8_t scancode);
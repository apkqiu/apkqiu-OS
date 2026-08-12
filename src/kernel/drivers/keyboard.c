// src/kernel/keyboard.c
#include "keyboard.h"
#include <stdbool.h>
#include <stdint.h>
#include "../kernelio.h"   // inb, outb

// ---------- 静态状态 ----------
static bool key_state[256];          // 所有扫描码状态（含扩展码）
static bool shift_pressed = false;
static bool ctrl_pressed = false;
static bool alt_pressed = false;
static bool caps_lock_on = false;
static bool extended = false;        // 0xE0 前缀标记

// ---------- Scan Code Set 1 映射表 ----------
static const char normal_table[0x58] = {
    0,   0,   '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,   0,
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 0,   0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,   '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,   0,   0,   ' '
};

static const char shift_table[0x58] = {
    0,   0,   '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', 0,   0,
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', 0,   0,
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~', 0,   '|',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0,   0,   0,   ' '
};

// ---------- 辅助函数 ----------
static char scancode_to_ascii(uint8_t sc, bool shift, bool caps) {
    if (sc >= 0x58) return 0;
    char c = shift ? shift_table[sc] : normal_table[sc];
    // 处理字母大小写
    if (c >= 'a' && c <= 'z') {
        if (caps) c = shift ? c : c - 0x20; // Caps+Shift 产生小写（根据标准）
    } else if (c >= 'A' && c <= 'Z') {
        if (caps) c = shift ? c : c + 0x20;
    }
    return c;
}

// ---------- 公开函数：初始化 ----------
void keyboard_init(void) {
    // 清空状态表
    for (int i = 0; i < 256; ++i) key_state[i] = false;
    shift_pressed = ctrl_pressed = alt_pressed = caps_lock_on = extended = false;
}

// ---------- 公开函数：处理扫描码 ----------
char keyboard_process_scancode(uint8_t scancode) {
    // 处理扩展码前缀 0xE0
    if (scancode == 0xE0) {
        extended = true;
        return 0;
    }

    uint8_t key = scancode & 0x7F;
    bool pressed = !(scancode & 0x80);

    // 若是扩展码，将索引偏移 128
    if (extended) {
        key += 128;
        extended = false;
    }

    // 更新状态数组
    key_state[key] = pressed;

    // 更新修饰键
    switch (key) {
        case 0x2A: case 0x36: shift_pressed = pressed; break;   // 左/右 Shift
        case 0x1D: ctrl_pressed = pressed; break;               // Ctrl
        case 0x38: alt_pressed = pressed; break;                // Alt
        case 0x3A: if (pressed) caps_lock_on = !caps_lock_on; break; // Caps Lock
        // 可添加 NumLock、ScrollLock 等
    }

    // 仅当普通键按下且非扩展码时产生字符
    if (pressed && key < 0x58) {
        char ascii = scancode_to_ascii(key, shift_pressed, caps_lock_on);
        return ascii;
    }
    return 0;
}
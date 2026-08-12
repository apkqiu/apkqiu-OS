#include "serial.h"
#include "../../kernelio.h"
// 定义COM1串口的基地址（x86标准）
#define COM1_PORT 0x3F8


// 检查串口发送器是否准备好（如果不检查，可能会丢字符）
int serial_is_transmit_empty() {
    // 读取线路状态寄存器（偏移量5），检查第5位是否为1
    return inb(COM1_PORT + 5) & 0x20;
}

// 输出一个字符到串口（核心函数）
void serial_putchar(const TTY* tty, const char c) {
    // 如果遇到换行符，先发送回车符，确保终端显示对齐（重要！）
    if (c == '\n') {
        serial_putchar(tty, '\r');
    }
    // 等待硬件准备好
    while (serial_is_transmit_empty() == 0);
    // 将字符写入发送保持寄存器（偏移量0）
    outb(COM1_PORT, c);
}

void serial_init() {
    outb(COM1_PORT + 1, 0x00);    // 禁用所有中断
    outb(COM1_PORT + 3, 0x80);    // 启用 DLAB（访问波特率除数寄存器）
    outb(COM1_PORT + 0, 0x01);    // 低字节：115200 对应除数 1
    outb(COM1_PORT + 1, 0x00);    // 高字节：0
    outb(COM1_PORT + 3, 0x03);    // 8位数据，1停止位，无校验（8N1）
    outb(COM1_PORT + 2, 0xC7);    // 启用 FIFO，清空缓冲区
    outb(COM1_PORT + 4, 0x0B);    // 启用 IRQ，RTS/DTR
}

void setup_tty_serial(TTY* tty){
    serial_init();
    tty->driver_type = SERIAL_TTY_DRIVER_TYPE;
    tty->putchar = serial_putchar;
}
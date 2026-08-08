#include "drivers/display/vga_text.h"
#include "drivers/tty/serial.h"
#include "drivers/tty/screen_text.h"
#include "drivers/keyboard.h"
#include "std/stdio.h"
#include <stdint.h>
#include "memory/memory_probe.h"
#include "kernelio.h"
#include "system/idt.h"
#include "std/queue.h"
// #include "memory/phys.h"
void kernel_main()
{
    Display display;
    setup_display_vga_text(&display);
    TTY serial;
    setup_tty_serial(&serial);
    TTY tty;
    setup_tty_screen_text(&tty, &display);

    MemoryInfo *meminfo = (MemoryInfo *)MEMINFO_PHYS_ADDR;

    // pmm_init(meminfo->entries, meminfo->region_count);
    init_idt();
    keyboard_init();
    while (1)
    {
        IntEvent evt;
        if (queue_dequeue(&interrupt_queue,&evt))
        {
            char c = keyboard_process_scancode(evt.data);
            ttyprintf(&tty, "%c", c);

        }
        else
        {
            __asm__ volatile("hlt");
        }
    }
}

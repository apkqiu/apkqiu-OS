#include "drivers/display/vga_text.h"
#include "drivers/tty/serial.h"
#include "drivers/tty/screen_text.h"
#include "drivers/keyboard.h"
#include "std/stdio.h"
#include <stdint.h>
#include "system/memory/memory_probe.h"
#include "kernelio.h"
#include "system/idt.h"
#include "std/queue.h"
// #include "memory/paging.h"
const MemoryInfo *meminfo = (MemoryInfo *)MEMINFO_PHYS_ADDR;
Display display;
TTY serial;
TTY tty;


void kernel_main()
{
    setup_tty_serial(&serial);
    setup_display_vga_text(&display);
    setup_tty_screen_text(&tty, &display);
    keyboard_init();
    init_idt();

    ttyprintf(&serial, "Hello From Kernel\n");
    // init_paging();
    double a = 1.33;
    ttyprintf(&tty, "%lf\n", a * a * a);
    ttyprintf(&tty, "# Base             Length       Type Virtual Range(Wants)\n");
    uint64_t total_avail = 0;
    for (uint8_t i = 0; i < meminfo->region_count; i++)
    {
        const E820Entry *entry = meminfo->entries + i;
        ttyprintf(&tty, "%1d %16llp %12llu %4u\n", i + 1, entry->base, entry->length, entry->type);
        if(entry->type && i != 0) {
            total_avail += entry->length;
        }
    }
    ttyprintf(&tty, "Total Memory: %llu", total_avail);

    while (1)
    {
        IntEvent evt;
        if (queue_dequeue(&interrupt_queue, &evt))
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

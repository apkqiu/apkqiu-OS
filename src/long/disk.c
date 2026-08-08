// kernel/disk.cpp
#include <stdint.h>
#include "kernelio.h"
// 声明外部 I/O 函数

#define ATA_DATA            0x1F0
#define ATA_SECTOR_COUNT    0x1F2
#define ATA_LBA_LOW         0x1F3
#define ATA_LBA_MID         0x1F4
#define ATA_LBA_HIGH        0x1F5
#define ATA_DEVICE_HEAD     0x1F6
#define ATA_COMMAND         0x1F7
#define ATA_STATUS          0x1F7

#define ATA_SR_BSY          0x80
#define ATA_SR_DRQ          0x08
#define ATA_SR_ERR          0x01
#define ATA_CMD_READ_PIO    0x20

static inline void ata_wait_bsy() {
    while (inb(ATA_STATUS) & ATA_SR_BSY) ;
}

static inline bool ata_wait_drq() {
    uint8_t status;
    do {
        status = inb(ATA_STATUS);
        if (status & ATA_SR_ERR)
            return 0;
    } while (!(status & ATA_SR_DRQ));
    return 1;
}

uint8_t read_sectors(uint32_t lba, uint8_t count, void* buffer) {
    uint16_t* buf = (uint16_t*)buffer;

    if (lba + count > 0x0FFFFFFF) return 0;

    for (uint8_t sector = 0; sector < count; ++sector) {
        ata_wait_bsy();

        outb(ATA_SECTOR_COUNT, 1);
        outb(ATA_LBA_LOW,   (uint8_t)(lba & 0xFF));
        outb(ATA_LBA_MID,   (uint8_t)((lba >> 8) & 0xFF));
        outb(ATA_LBA_HIGH,  (uint8_t)((lba >> 16) & 0xFF));
        outb(ATA_DEVICE_HEAD, (uint8_t)(0xE0 | ((lba >> 24) & 0x0F)));
        outb(ATA_COMMAND, ATA_CMD_READ_PIO);

        if (!ata_wait_drq())
            return false;

        for (int i = 0; i < 256; ++i) {
            buf[i] = inw(ATA_DATA);
        }

        lba++;
        buf += 256;
    }

    ata_wait_bsy();
    return 1;
}
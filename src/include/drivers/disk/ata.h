// kernel/disk.h
#pragma once
#include <stdint.h>
#include "drivers/disk/base.h"
void setup_disk_ata(Disk*);

#define ATA_DISK_DRIVER_TYPE     0x01
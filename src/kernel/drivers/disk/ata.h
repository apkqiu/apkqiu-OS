// kernel/disk.h
#pragma once
#include <stdint.h>
#include "base.h"
void setup_disk_ata(Disk*);

#define ATA_DISK_DRIVER_TYPE     0x01
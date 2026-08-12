#pragma once
#include <stdint.h>
#include "../../status.h"
typedef struct Disk
{
    uint8_t driver_type;
    status_t (*read)(const struct Disk *disk, uint32_t lba, uint8_t count, void *buffer);
    status_t (*write)(const struct Disk *disk, uint32_t lba, uint8_t count, void *buffer);
} Disk;
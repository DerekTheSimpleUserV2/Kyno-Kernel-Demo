// fat32-driver.c 0.1
// License: BSD

#include <stdint.h>
#include "fat32.h"

typedef struct {
    uint8_t jumpBoot[3];
    char OEMName[8];
    uint16_t bytesPerSector;
    uint8_t sectorsPerCluster;
    uint16_t reservedSectorCount;
    uint8_t numFATs;
    uint32_t sectorsPerFAT;
    uint32_t rootCluster;
} __attribute__((packed)) FAT32_BPB;

static FAT32_BPB bpb;

extern void kprint(const char *str);

// Inicializa FAT32 leyendo el BPB
int fat32_init(uint8_t *sector) {
    bpb = *(FAT32_BPB*)sector;
    kprint("FAT32 Started.\n");
    return 0;
}

// Función mínima para abrir un archivo (placeholder)
int fat32_open(const char *filename) {
    kprint("FAT32: Opening File ");
    kprint(filename);
    kprint("\n");
    return 0;
}

// fat32-header.h 0.1
// License: BSD

#ifndef FAT32_H
#define FAT32_H

int fat32_init(uint8_t *sector);
int fat32_open(const char *filename);

#endif

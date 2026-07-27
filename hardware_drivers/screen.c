// screen.c
#include "screen.h"

#define VIDEO_MEMORY 0xB8000
#define MAX_COLS 80
#define MAX_ROWS 25

int cursor_x = 0;
int cursor_y = 0;

void putchar(char c) {
    unsigned char *vidmem = (unsigned char*) VIDEO_MEMORY;
    int pos = (cursor_y * MAX_COLS + cursor_x) * 2;
    vidmem[pos] = c;
    vidmem[pos+1] = 0x07; // color gris sobre negro
    cursor_x++;
    if (cursor_x >= MAX_COLS) {
        cursor_x = 0;
        cursor_y++;
    }
}

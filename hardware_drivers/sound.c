// sound.c
#include "sound.h"

// Usando el PIT (Programmable Interval Timer) para generar tonos
void play_sound(unsigned int freq) {
    unsigned int div = 1193180 / freq;
    outb(0x43, 0xB6);
    outb(0x42, (unsigned char)(div));
    outb(0x42, (unsigned char)(div >> 8));
    unsigned char tmp = inb(0x61);
    if (tmp != (tmp | 3)) {
        outb(0x61, tmp | 3);
    }
}

void stop_sound() {
    unsigned char tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

CC = gcc
ASM = nasm
CFLAGS = -m32 -ffreestanding -O2
LDFLAGS = -T linker.ld -nostdlib

all: kyno.bin

kyboot.o: kyboot.asm
  $(ASM) -f elf32 kyboot.asm -o kyboot.o

kyno.o: kyno.c
  $(CC) $(CFLAGS) -c kyno.c -o kyno.o

kynner.o: kynner.c
  $(CC) $(CFLAGS) -c kynner.c -o kynner.o

fat32-driver.o: fat32-driver.c
  $(CC) $(CFLAGS) -c fat32-driver.c -o fat32-driver.o

kernel.bin: kyboot.o kyno.o kynner.o fat32-driver.o
  ld $(LDFLAGS) -o kernel.bin kyboot.o kyno.o kynner.o fat32-driver.o

clean:
  rm -f *.o *.bin

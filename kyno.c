// Kyno Kernel 0.1 
// LICENSE: BSD

#include <stdint.h>

// Definición de tipos básicos
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

// Prototipos
void kprint(const char *str);
void kyno_init(void);
void kynner_schedule(void);

// Función para imprimir en pantalla (modo texto VGA)
static volatile u16* vga_buffer = (u16*)0xB8000;
static u16 vga_index = 0;

void kprint(const char *str) {
    while (*str) {
        vga_buffer[vga_index++] = (u16)(*str | 0x0F00); // Texto blanco sobre negro
        str++;
    }
}

// Inicialización del kernel
void kyno_init(void) {
    kprint("Kyno Kernel (BSD Licensed)\n");
    kprint("Inicializando memoria...\n");
    kprint("Inicializando interrupciones...\n");
    kprint("Inicializando Kynner Scheduler...\n");
    kprint("Inicializando FAT32...\n");
}

// Planificador básico (placeholder)
void kynner_schedule(void) {
    kprint("Kynner: ejecutando proceso...\n");
}

// Punto de entrada del kernel
void kmain(void) {
    kyno_init();
    while (1) {
        kynner_schedule();
        // Aquí iría el cambio de contexto y multitarea
    }
}

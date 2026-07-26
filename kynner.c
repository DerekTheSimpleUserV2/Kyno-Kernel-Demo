// Kynner 0.1
// License: BSD

#include <stdint.h>

extern void kprint(const char *str);

typedef struct {
    int pid;
    const char *name;
} process_t;

process_t processes[] = {
    {1, "Process A"},
    {2, "Process B"},
    {3, "Process C"}
};

int current = 0;
int total = 3;

void kynner_schedule(void) {
    kprint("Kynner: Executing ");
    kprint(processes[current].name);
    kprint("\n");

    current = (current + 1) % total;
}


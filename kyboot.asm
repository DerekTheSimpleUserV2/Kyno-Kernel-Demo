; Kyboot 0.1
; License: BSD

BITS 16
ORG 0x7C00

start:
    ; Mensaje en pantalla
    mov si, msg
    call print_string

    ; Cambiar a modo protegido
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp 0x08:protected_mode

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

msg db "Kyboot Loading Kyno Kernel...",0

; GDT mínima
gdt:
    dq 0x0000000000000000
    dq 0x00CF9A000000FFFF ; Código
    dq 0x00CF92000000FFFF ; Datos
gdt_descriptor:
    dw gdt_end - gdt - 1
    dd gdt
gdt_end:

protected_mode:
    ; Aquí cargarías el kernel Kyno en memoria
    ; y saltarías a su punto de entrada kmain
    ; (placeholder)
    hlt

TIMES 510-($-$$) db 0
DW 0xAA55


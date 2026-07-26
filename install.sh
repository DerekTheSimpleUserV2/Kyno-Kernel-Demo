#!/bin/bash

echo "Instalando dependencias para Kyno Kernel..."

if command -v apt >/dev/null; then
    sudo apt update
    sudo apt install build-essential nasm qemu-system-x86 -y
elif command -v dnf >/dev/null; then
    sudo dnf install gcc make nasm qemu -y
elif command -v yum >/dev/null; then
    sudo yum install gcc make nasm qemu -y
elif command -v zypper >/dev/null; then
    sudo zypper install gcc make nasm qemu -y
elif command -v pacman >/dev/null; then
    sudo pacman -Sy --noconfirm base-devel nasm qemu
else
    echo "Gestor de paquetes no reconocido. Instala manualmente: gcc, make, nasm, qemu."
    exit 1
fi

echo "✅ Dependencias instaladas correctamente."

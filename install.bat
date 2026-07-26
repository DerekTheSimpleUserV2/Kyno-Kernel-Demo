@echo off
echo Instalando dependencias para Kyno...
winget install -e --id GnuWin32.Make
winget install -e --id NASM.NASM
winget install -e --id QEMU.QEMU
echo Listo!

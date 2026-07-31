// Fragmento dentro de kyboot-efi.c

// Leer el archivo del kernel en memoria
EFI_FILE_INFO *FileInfo;
UINTN FileInfoSize = SIZE_OF_EFI_FILE_INFO + 200;
FileInfo = AllocatePool(FileInfoSize);

status = uefi_call_wrapper(KernelFile->GetInfo, 4,
                           KernelFile,
                           &gEfiFileInfoGuid,
                           &FileInfoSize,
                           FileInfo);
if (EFI_ERROR(status)) {
    Print(L"Error 232: Kyno failed to retrieve information from the directory or file\n");
    return status;
}

UINTN KernelSize = FileInfo->FileSize;
VOID *KernelBuffer = AllocatePool(KernelSize);

status = uefi_call_wrapper(KernelFile->Read, 3,
                           KernelFile,
                           &KernelSize,
                           KernelBuffer);
if (EFI_ERROR(status)) {
    Print(L"Error 021: Kyboot failed to Reading The Kernel  \n");
    return status;
}

Print(L"Kernel Kyno Loaded on The memory (%d bytes)\n", KernelSize);

// Aquí deberías saltar al punto de entrada del kernel
// typedef void (*KynoEntry)(void);
// KynoEntry entry = (KynoEntry)KernelBuffer;
// entry();

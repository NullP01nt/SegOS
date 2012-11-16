.global loader              # expose entry point to linker

.set MBOOT_ALIGN,   1 << 0  # align loaded modules on page bounds
.set MBOOT_MEMINFO, 1 << 1  # provide memory map
.set MBOOT_FLAGS,   MBOOT_ALIGN | MBOOT_MEMINFO
.set MBOOT_MAGIC,   0x1BADB002
.set CHECKSUM,      -(MBOOT_MAGIC + MBOOT_FLAGS)

.align 4
.long MBOOT_MAGIC
.long MBOOT_FLAGS
.long CHECKSUM

.set STACKSIZE, 0x4000
.comm stack, STACKSIZE, 32
.comm mbd, 4
.comm magic, 4

loader:
    movl    $(stack + STACKSIZE), %esp  # Set up the stack
    movl    %eax, magic                 # Multiboot magic number
    movl    %ebx, mbd                   # Multiboot data struct

    call    kmain
    cli
hang:
    hlt
    jmp     hang

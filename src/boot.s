.set MBOOT_ALIGN,   1 << 0  # align loaded modules on page bounds
.set MBOOT_MEMINFO, 1 << 1  # provide memory map
.set MBOOT_FLAGS,   MBOOT_ALIGN | MBOOT_MEMINFO
.set MBOOT_MAGIC,   0x1BADB002
.set CHECKSUM,      -(MBOOT_MAGIC + MBOOT_FLAGS)

.section .multiboot
.align 4
.long MBOOT_MAGIC
.long MBOOT_FLAGS
.long CHECKSUM

.section .bs_stack
stack_bottom:
.skip 16384 # 16KiB
stack_top:
.comm mbd, 4
.comm magic, 4

.section .text
.global _start				# expose entry point to linker
.type _start, @function
_start:
    movl    $stack_top, %esp  # Set up the stack
    #movl    %eax, magic                 # Multiboot magic number
    #movl    %ebx, mbd                   # Multiboot data struct

    call    kmain
    cli
    hlt
_hang:
    jmp     _hang

.size _start, . - _start

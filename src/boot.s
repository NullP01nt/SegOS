.set ALIGN,		1<<0					# Align loaded modules on page boundaries
.set MEMINFO,	1<<1					# provide memory map
.set MB_FLAGS,	ALIGN | MEMINFO			# The MultiBoot flags
.set MB_MAGIC,	0x1BADB002				# MultiBoot magic number
.set MB_CHKSM,	-(MB_MAGIC+MB_FLAGS)	# Final MultiBoot check

.section .multiboot
.align	4
.long	MB_MAGIC
.long	MB_FLAGS
.long	MB_CHKSM

.section .bststack
bststack_btm:
.skip 16384
bststack_top:

.section .text
.global _start
.type _start, @function
_start:
	movl $bststack_top, %esp
	call kernel_main

	cli
	hlt
_hang:
	jmp _hang

.size _start, . - _start


IMG = floppy.img
KERNEL_BIN = src/kernel.bin
DIRS = src

all: $(IMG)

$(IMG): $(KERNEL_BIN)
	dd if=/dev/zero of=grub/pad bs=1 count=750
	cat grub/stage1 grub/stage2 grub/pad src/kernel.bin > $(IMG)

clean:
	rm $(IMG)

# --- Project Details ----------------------------------------------

TARGET	:= kernel

OBJS	:= boot.o kernel.o screen.o cpu.o mem.o stdio.o

# --- Build defines ------------------------------------------------

PREFIX	:= i586-elf-
CC 	:= $(PREFIX)gcc
LD	:= $(PREFIX)ld
AS	:= $(PREFIX)as

CFLAGS  = -Wall -Wextra -nostdlib -nostdinc -fno-builtin -nostartfiles -nodefaultlibs -fno-stack-protector -I./ -lgcc
LDFLAGS = -Tlinker.ld
ASFLAGS =

.PHONY	: build clean

# --- Build --------------------------------------------------------

build: $(TARGET).bin

$(TARGET).bin : $(OBJS) link

.s.o:
	@$(AS) $(ASFLAGS) $< -o $@

.c.o:
	@$(CC) $(CFLAGS) -o $@ -c $<

link:
	@$(LD) $(LDFLAGS) -o $(TARGET).bin $(OBJS)

# --- Clean --------------------------------------------------------

clean:
	@rm -fv *.bin
	@rm -fv *.o

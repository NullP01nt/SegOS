#ifndef STDIO_H
#define STDIO_H

#include <sys/types.h>

void outb(u16int port, u8int data);
u8int inb(u16int port);
u16int inw(u16int port);

#endif

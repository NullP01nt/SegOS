#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <types.h>
#include <mem.h>
#include <cpu.h>

void outb(u16int port, u8int data);
u8int inb(u16int port);
u16int inw(u16int port);
#endif

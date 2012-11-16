#include <stdio.h>

void outb(u16int port, u8int data)
{
    asm volatile ("outb %1, %0" :: "dN"(port), "a"(data));
}

u8int inb(u16int port)
{
    u8int val;
    asm volatile ("inb %1, %0" : "=a"(val) : "dN"(port));
    return val;
}

u16int inw(u16int port)
{
    u16int val;
    asm volatile ("inw %1, %0" : "=a"(val) : "dN"(port));
    return val;
}

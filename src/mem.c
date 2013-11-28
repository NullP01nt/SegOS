#include <sys/mem.h>

void memcpy(u8int *dest, const u8int *src, u32int len)
{
    const u8int *sp = (const u8int*)src;
    u8int *dp = (u8int*)dest;
    for(;len != 0; len--) *dp++ = *sp++;
}

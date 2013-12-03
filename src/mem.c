#include <system.h>

void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
    const uint8_t *sp = (const uint8_t*)src;
    uint8_t *dp = (uint8_t*)dest;
    for(;len != 0; len--) *dp++ = *sp++;
}

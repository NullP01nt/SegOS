#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <stdint.h>
#include <stddef.h>


/**** CPU.C ****/
enum cpuid_req_t {
    CPUID_GETVENDORSTRING,
    CPUID_GETFEATURES,
    CPUID_GETTLB,
    CPUID_GETSERIAL,
    CPUID_INTELEXTENDED=0x80000000,
    CPUID_INTELFEATURES,
    CPUID_INTELBRANDSTRING,
    CPUID_INTELBRANDSTRINGMORE,
    CPUID_INTELBRANDSTRINGEND,
};

/** issue a single request to CPUID. Fits 'intel features', for instance
 *  *  note that even if only "eax" and "edx" are of interest, other registers
 *   *  will be modified by the operation, so we need to tell the compiler about it.
 *    */
void cpuid(enum cpuid_req_t code, uint32_t *a, uint32_t *d);

/** issue a complete request, storing general registers output as a string
 *  */
int cpuid_string(enum cpuid_req_t code, uint32_t where[4]);

/**** MEM.C ****/
void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);
//{
//    const u8int *sp = (const u8int*)src;
//    u8int *dp = (u8int*)dest;
//    for(;len != 0; len--) *dp++ = *sp++;
//}

#endif

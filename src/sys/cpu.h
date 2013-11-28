#ifndef __CPU_H
#define __CPU_H

#include <sys/types.h>

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
void cpuid(enum cpuid_req_t code, u32int *a, u32int *d);

/** issue a complete request, storing general registers output as a string
 *  */
int cpuid_string(enum cpuid_req_t code, u32int where[4]);
#endif

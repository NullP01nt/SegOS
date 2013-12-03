#include <stddef.h>
#include <stdint.h>
#include <term.h>
#include <system.h>
 
/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

void print_cpu()
{
	uint32_t words[4];
	term_puts("--- Detecting CPU ---\n");
	cpuid_string(CPUID_GETVENDORSTRING, words);
	char brand[12];
	memcpy((uint8_t*)&brand[0],(uint8_t*)&words[1],4);
    memcpy((uint8_t*)&brand[4],(uint8_t*)&words[3],4);
    memcpy((uint8_t*)&brand[8],(uint8_t*)&words[2],4);
    term_puts(brand);
}

void kernel_main()
{
	term_init();
	term_clr();
//	/* Since there is no support for newlines in terminal_putchar yet, \n will
//	   produce some VGA specific character instead. This is normal. */
	term_puts("SegOS Booting!\n");
	print_cpu();
	while(1);
}

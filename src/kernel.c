#include <system.h>
#include <io/screen.h>

void kmain(void)
{
    extern u32int magic;
    extern void *mbd;

    if ( magic != 0x2BADB002 ) {
        // Something went wrong
    }
    cls();
    puts("SegOS booting!\n");
	u32int words[4];
    cpuid_string(CPUID_GETVENDORSTRING, words);
//    int i;
//    for(i = 0; i < 4; i++)
//    {
//        putch(65+i);
//        puts(": ");
//        puthex(words[i]);
//        putch('\n');
//    }
    char brand[12];
    memcpy((u8int*)&brand[0],(u8int*)&words[1],4);
    memcpy((u8int*)&brand[4],(u8int*)&words[3],4);
    memcpy((u8int*)&brand[8],(u8int*)&words[2],4);
	puts("CPU Brand: ");
    puts(brand);
    while(1);
}

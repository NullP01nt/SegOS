#include <system.h>
#include <screen.h>

u16int *vram = (u16int*)0xB8000;
u8int crs_x;
u8int crs_y;
u8int attrib = 0x0F;

static void move_cursor() {
    u16int cursor_loc = crs_y * 80 + crs_x;
    outb(0x3D4, 14);
    outb(0x3D5, cursor_loc >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, cursor_loc);
}

static void scroll(void)
{
    u16int blank = 0x20 | (attrib << 8);
    if (crs_y >= 25)
    {
        int i;
        for(i = 0*80; i < 24*80; i++) {
            vram[i] = vram[i+80];
        }

        for(i = 24*80; i < 25*80; i++) {
            vram[i] = blank;
        }
        crs_y = 24;
    }
}

void putch(char c) {
    u16int *location;
    if (c == 0x08 && crs_x)
    {
        crs_x--;
    }
    else if (c == 0x09)
    {
        crs_x = (crs_x+8) & ~(8-1);
    }
    else if (c == '\r')
    {
        crs_x = 0;
    }
    else if (c == '\n')
    {
        crs_x = 0;
        crs_y++;
    }
    else if (c >= ' ')
    {
        location = vram + (crs_y*80+crs_x);
        *location = c | (attrib << 8);
        crs_x++;
    }

    if(crs_x >= 80)
    {
        crs_x = 0;
        crs_y++;
    }
    scroll();
    move_cursor();
}

void puts(char *s) {
    int i = 0;
    while(s[i]) {
        putch(s[i++]);
    }
}

void cls(void)
{
    u16int blank = 0x20 | (attrib << 8);
    int i;
    for(i = 0; i < 80*25; i++) {
        vram[i] = blank;
    }

    crs_x = 0;
    crs_y = 0;
    move_cursor();
}

void puthex(u32int v) {
    s32int tmp;
    puts("0x");

    char noZeroes = 1;

    int i;
    for(i=28; i>0; i -= 4) {
        tmp = (v >> i) & 0xF;
        if (tmp == 0 && noZeroes != 0) {
            continue;
        }

        if (tmp >= 0xA) {
            noZeroes = 0;
            putch(tmp-0xA+'a');
        } else {
            noZeroes = 0;
            putch(tmp+'0');
        }
    }

    tmp = v & 0xF;
    if (tmp >= 0xA) {
        putch(tmp-0xA+'a');
    } else {
        putch(tmp+'0');
    }
}

void monitor_write_dec(u32int n) {
    if(n == 0) {
        putch('0');
        return;
    }

    s32int acc = n;
    char c[32];
    int i=0;
    while(acc > 0) {
        c[i] = '0'+acc%10;
        acc /= 10;
        i++;
    }
    c[i] = 0;

    char c2[32];
    c2[i--] = 0;
    int j = 0;
    while (i >= 0) {
        c2[i--] = c[j++];
    }
    puts(c2);
}

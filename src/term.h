#ifndef __TERM_H
#define __TERM_H

#include <stdint.h>
#include <stddef.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 24;
 
size_t term_row;
size_t term_col;
uint8_t term_color;
uint16_t* term_buff;

/* Hardware text mode color constants. */
enum vga_color
{
	BLACK			= 0x0,
	BLUE			= 0x1,
	GREEN			= 0x2,
	CYAN			= 0x3,
	RED				= 0x4,
	MAGENTA			= 0x5,
	BROWN			= 0x6,
	LIGHT_GREY		= 0x7,
	DARK_GREY		= 0x8,
	LIGHT_BLUE		= 0x9,
	LIGHT_GREEN		= 0xA,
	LIGHT_CYAN		= 0xB,
	LIGHT_RED		= 0xC,
	LIGHT_MAGENTA	= 0xD,
	LIGHT_BROWN		= 0xE,
	WHITE			= 0xF,
};

void term_set_color(enum vga_color fg, enum vga_color bg);
size_t strlen(const char* str);

void term_init();
void term_clr();
void term_scroll();

void term_putch(char c);
void term_puts(const char* string);
#endif

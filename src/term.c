#include <stdint.h>
#include <stddef.h>
#include <term.h>

void term_set_color(enum vga_color fg, enum vga_color bg)
{
	term_color = fg | bg << 4;
}

size_t strlen(const char* str)
{
	size_t ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}
 
void term_init()
{
	term_row = 0;
	term_col = 0;
	term_set_color(WHITE, BLACK);
	term_buff = (uint16_t*) 0xB8000;
}

void term_clr()
{
	size_t x, y;
	for ( y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			term_buff[index] = ' ' | term_color << 8;
		}
	}
}
 
void term_putch(char c)
{
	if(c == '\n') {
		term_col = 0;
		term_row++;
	} else if (c == '\r') {
		term_col = 0;
	} else {
		const size_t index = term_row * VGA_WIDTH + term_col++;
		term_buff[index] = c | term_color << 8;
	}
	term_scroll();
}

void term_scroll()
{
	if ( term_col == VGA_WIDTH )
	{
		term_col = 0;
		term_row++;
	}
	if ( term_row == VGA_HEIGHT )
	{
		term_row = 0;
	}
}

void term_puts(const char* string)
{
	size_t i = 0;
	while(string[i]!=0)	term_putch(string[i++]);
}
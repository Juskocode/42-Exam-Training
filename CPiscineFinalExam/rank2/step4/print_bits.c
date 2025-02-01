#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	print_bits(unsigned char c)
{
	for (int i = 8; i >= 0; i--)
	{
		char b = (c & (1 << i)) ? '1' : '0';
		f(b);
	}
}

#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	f_pb(unsigned char c)
{
	int i = 8;
	while (i >= 0)
	{
		char b = (c & (1 << i)) ? '1' : '0';
		f(b);
		i--;
	}
	f('\n');
}

unsigned char reverse_bits(unsigned char c)
{
	int i = 0, res = 0;
	while (i < 8)
	{
		res <<= 1;
		res |= (c & 1);
		c >>= 1;
		i++;
	}
	return res;
}

int	main(void)
{
	unsigned char c = 81;
	f_pb(81);
	unsigned char c1 = reverse_bits(c);
	f_pb(c1);
	return 0;
}

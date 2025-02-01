#include <unistd.h>
void	f(char c){write(1, &c, 1);}

void	ft_print_bits(unsigned char c)
{
	int i = 7;
	while (i >= 0)
	{
		char bit = (c & (1 << i)) ? '1' : '0';
		f(bit);
		i--;
	}
	f('\n');
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(void)
{
	unsigned char c = 1;
	ft_print_bits(c);
	unsigned char c1 = swap_bits(c);
	ft_print_bits(c1);
	return 0;
}

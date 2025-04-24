#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	print_bits(unsigned char c)
{
	for (int i = 7; i >= 0; i--)
		f((c & (1 << i)) ? '1' : '0');
}

int	main(int ac, char **av)
{
	print_bits(144);
	f('\n');
	return 0;
}

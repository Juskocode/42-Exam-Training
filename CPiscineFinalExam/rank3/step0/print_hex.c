#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	ft_atoi(char *s)
{
	int i = 0, res = 0, si = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			si = -si;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += (s[i] - '0');
		i++;
	}
	return (res * si);
}

void	ft_print_hex(int n, char *base)
{
	if (n < 16)
	{
		f(base[n]);
		return ;
	}
	ft_print_hex(n / 16, base);
	ft_print_hex(n % 16, base);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char base[] = "0123456789abcdef";
		ft_print_hex(ft_atoi(av[1]), base);		
	}
	f('\n');
	return 0;
}

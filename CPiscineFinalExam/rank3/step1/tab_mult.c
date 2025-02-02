#include <unistd.h>

int	ft_atoi(char *s)
{
	int i = 0, res = 0, si = 1;
	while (s[i] >= 9 && s[i] <= 13)
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

void	f(char c){write(1, &c, 1);}

void	ft_putnbr(int nb)
{
	long n = nb;
	if (n < 0)
	{
		f('-');
		n = -n;
	}
	if (n < 10)
	{
		f(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}

void	ft_print_tab_mul(int n)
{
	int i = 1, val = n;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(val);
		f('\n');
		val += n;
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_print_tab_mul(ft_atoi(av[1]));		
	}
	f('\n');
	return 0;
}

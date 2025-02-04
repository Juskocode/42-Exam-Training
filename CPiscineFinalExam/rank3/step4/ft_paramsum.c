#include <unistd.h>

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

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		ft_putnbr(ac - 1);
	}
	f('\n');
	return 0;
}

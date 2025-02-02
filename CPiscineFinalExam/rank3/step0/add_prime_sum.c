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

int	ft_atoi(char *s)
{
	int i = 0, si = 1, res = 0;
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

int	ft_prime(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int	main(int ac, char **av)
{
	int sum = 0;
	if (ac == 2)
	{
		int n = ft_atoi(av[1]);
		for (int i = 2; i <= n; i++)
			sum += i * ft_prime(i);
	}
	ft_putnbr(sum);
	f('\n');
	return 0;
}

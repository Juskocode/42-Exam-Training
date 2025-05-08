#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

int	ft_atoi(const char *s)
{
	int si = 1, n = 0, i = 0;
	while (s[i] >= 9 && s[i] <= 13 || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			si = -si;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += (s[i] - '0');
		i++;
	}
	return n * si;
}

void	fn(unsigned int n)
{
	if (n < 10)
		f(n + '0');
	else
	{
		fn(n / 10);
		fn(n % 10);
	}
}

void	fprime(unsigned int n)
{
	int i = 2;
	if (n == 1)
		fn(1);
	while (i <= n)
	{
		if (!(n % i))
		{
			fn(i);
			if (n != i)
				f('*');
			n = n / i;
		}
		else
			i++;
	}
	f('\n');
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		unsigned int val = ft_atoi(av[1]);
		fprime(val);
	}
	f('\n');
	return 0;
}

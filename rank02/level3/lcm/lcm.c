#include <unistd.h>
#include <stdio.h>

unsigned int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

void	f(char c){write(1, &c, 1);}

void	fnb(unsigned int n)
{
	if (n <= 9)
		f(n + '0');
	else
	{
		fnb(n / 10);
		fnb(n % 10);
	}
}

int	ft_atoi(char *s)
{
	int n = 0, si = 1, i = 0;
	while (s[i] >= 9 && s[i] <= 13 || s[i] == ' ' )
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
	return (n * si);
}

unsigned int ft_abs(int a)
{
	return (a > 0) ? a : -a;
}

unsigned int    lcm(unsigned int a, unsigned int b);

int	main(int ac, char** av)
{
	if (ac == 3)
	{
		unsigned int a = ft_atoi(av[1]), b = ft_atoi(av[2]);
		unsigned int lcm = ft_abs(a * b) / gcd(a, b);
		fnb(lcm);
		f('\n');
	}
	f('\n');
	return 0;
}


























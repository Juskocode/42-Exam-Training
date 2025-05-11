#include <unistd.h>

void	f(char c){write(1, &c, 1);}

unsigned int	ft_atoi(const char *s)
{
	size_t i = 0;
	unsigned int n = 0;
	while (s[i] >= 9 && s[i] <= 13 || s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += (s[i] - '0');
		i++;
	}
	return n;
}

void	fui(unsigned int n)
{
	if (n < 10)
		f(n + '0');
	else
	{
		fui(n / 10);
		fui(n % 10);
	}
}

unsigned int	pgcd(unsigned int a, unsigned int b)
{
	if(!b)
		return a;
	return pgcd(b, a % b);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		unsigned int a = ft_atoi(av[1]), b = ft_atoi(av[2]);
		unsigned int g = pgcd(a, b);
		fui(g);
	}
	f('\n');
	return 0;
}

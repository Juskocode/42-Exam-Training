#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

int	ft_atoi(const char *s)
{
	int i = 0, si = 1, n = 0;
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
		n *= 10;
		n += (s[i] - '0');
		i++;
	}
	return n * si;
}

void	ft_rotatex(const char *s, int r)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			f(('a' + (s[i] - 'a' + r) % 26));
		else if (s[i] >= 'A' && s[i] <= 'Z')
			f(('A' + (s[i] - 'A' + r) % 26));
		else
			f(s[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int r = ft_atoi(av[2]);
		ft_rotatex(av[1], r);
	}
	f('\n');
	return 0;
}

#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	ft_atoi(char *s)
{
	int i = 0, si = 1, res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
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


int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0, x = ft_atoi(av[2]);
		while (av[1][i])
		{
			char c = av[1][i];
			if (c >= 'a' && c <= 'z')
				f(((c - 'a' + x) % 26) + 'a');
			else if (c >= 'A' && c <= 'Z')
				f(((c - 'A' + x) % 26) + 'A');
			else
				f(c);
			i++;
		}
	}
	f('\n');
	return 0;
}

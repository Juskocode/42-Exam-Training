#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	ft_is_b(char c){return c == ' ' || c == '\t';}

int	ft_countw(char *s)
{
	int i = 0i, count = 0;
	while (s[i])
	{
		while (ft_is_b(s[i]))
			i++;
		if (s[i])
			count++;
		while (!ft_is_b(s[i]) && s[i])
			i++;
	}
	return count;
}

void	ft_printw(char *s)
{
	int i = 0, size = ft_countw(s);
	while (s[i])
	{
		while (ft_is_b(s[i]))
			i++;
		if (s[i])
			size--;
		while (!ft_is_b(s[i]) && s[i])
		{
			f(s[i]);
			i++;
		}
		if (size)
			f(' ');
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_printw(av[1]);
	}
	f('\n');
	return 0;
}

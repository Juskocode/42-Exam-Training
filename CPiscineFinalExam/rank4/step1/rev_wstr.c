#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	fb(char c){return c == ' ' || c == '\t';}

void	ft_printrev(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (fb(s[i]) && i >= 0)
			i--;
		while (!fb(s[i]) && i >= 0)
			i--;
		int j = i + 1;
		while (!fb(s[j]) && s[j])
		{
			f(s[j]);
			j++;
		}
		if (i >= 0)
			f(' ');
	}
}


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_printrev(av[1]);
	}
	f('\n');
}

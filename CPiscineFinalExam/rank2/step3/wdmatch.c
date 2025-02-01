#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	fs(char *s)
{
	int i = 0;
	while (s[i])
	{
		f(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0, j = 0;
		while (av[2][j])
		{
			if (av[1][i] == av[2][j])
				i++;
			if (!av[1][i])
			{
				fs(av[1]);
				break ;
			}
			j++;
		}
	}
	f('\n');
	return 0;
}

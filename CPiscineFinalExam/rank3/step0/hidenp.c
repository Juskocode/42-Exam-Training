#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0, j = 0;
		while (av[2][i])
		{
			if (av[1][j] == av[2][i])
				j++;
			i++;
		}
		if (!av[1][j])
			f('1');
		else
			f('0');
	}
	f('\n');
	return 0;
}

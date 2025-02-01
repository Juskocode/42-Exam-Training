#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char vis[128] = {0};
		int i = 0;
		while (av[2][i]){vis[(int)av[2][i++]]++;}
		i = 0;
		while (av[1][i])
		{
			if (vis[(int)av[1][i]])
			{
				vis[(int)av[1][i]] = 0;
				f(av[1][i]);
			}
			i++;
		}
	}
	f('\n');
	return (0);
}

#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		while (av[1][i])
		{
			if (av[1][i] == 'a')
			{
				f('a');
				f('\n');
				return (0);
			}
			i++;
		}
	}
	else
		f('a');
	f('\n');
	return 0;
}

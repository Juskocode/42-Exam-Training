#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i])
			i++;
		i--;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i--;
		int j = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i--;
		i++;
		while (i <= j)
			f(av[1][i++]);
	}
	f('\n');
	return 0;
}

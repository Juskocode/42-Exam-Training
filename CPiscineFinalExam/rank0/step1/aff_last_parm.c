#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	fs(char *str)
{
	int	i = 0;
	while (str[i])
	{
		f(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		fs(av[ac - 1]);
	}
	f('\n');
	return 0;
}

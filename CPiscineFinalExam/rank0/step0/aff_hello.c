#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	fs(char *str)
{
	int i = 0;
	while (str[i])
	{
		f(str[i]);
		i++;
	}
}

void	fgreeting(char *pessoa)
{
	write(1, "Hello, ", 7);
	fs(pessoa);
	write(1, "!\n", 2);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			fgreeting(av[i]);
			i++;
		}
		return 0;
	}
	f('\n');
	return 0;
}

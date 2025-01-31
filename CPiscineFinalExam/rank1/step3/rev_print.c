#include <unistd.h>

void	f(char c){write(1, &c, 1);}
int	flen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int s = flen(av[1]) - 1;
		while (s >= 0)
		{
			f(av[1][s]);
			s--;
		}
	}
	f('\n');
	return 0;
}

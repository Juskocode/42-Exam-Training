#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		//caso o char para encontrar tenha mais que um char
		if (av[2][1] || !av[2][0])
		{
			write(1, "\n", 1);
			return 0;
		}
		int i = 0;
		while (av[1][i])
		{
			if (av[1][i] == av[2][0])
			{
				write(1, &av[2][0], 1);
				write(1, "\n", 1);
				return 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}

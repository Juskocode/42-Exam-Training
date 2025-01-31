#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i])
		{
			char c = av[1][i];
			int idx = 1;
			if (c >= 'a' && c <= 'z')
				idx += c - 'a';
			else if (c >= 'A' && c <= 'Z')
				idx += c - 'A';
			while (idx--)
				f(c);
			i++;
		}
	}
	f('\n');
	return 0;
}

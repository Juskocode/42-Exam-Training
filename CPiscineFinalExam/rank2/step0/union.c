
#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	ft_print_unique(char *s, char *vis)
{
	int i = 0;
	while (s[i])
	{
		if (!vis[(int)s[i]])
		{
			vis[(int)s[i]]++;
			f(s[i]);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char vis[128] = {0};
		ft_print_unique(av[1], vis);
		ft_print_unique(av[2], vis);
	}
	f('\n');
	return (0);
}

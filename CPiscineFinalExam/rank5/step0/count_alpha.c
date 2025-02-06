#include <unistd.h>

void	f(char c){write(1, &c, 1);}

void	fn(int nb)
{
	if (nb < 10)
	{
		f(nb + '0');
		return ;
	}
	fn(nb / 10);
	fn(nb % 10);
}

int	is_lower(char c){return (c >= 'a' && c <= 'z');}
int	is_upper(char c){return (c >= 'A' && c <= 'Z');}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int vis[26] = {0};
		int i = 0, count = 0, k = 0;
		while (av[1][i])
		{
			char c;
			if (is_lower(av[1][i]))
				c = av[1][i] - 'a';
			if (is_upper(av[1][i]))
				c = av[1][i] - 'A';
			if (is_lower(av[1][i]) || is_upper(av[1][i]))
			{
				if (!vis[(int)c])
					count++;
				vis[(int)c]++;
			}
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			char c;
			if (is_lower(av[1][i]))
				c = av[1][i] - 'a';
			if (is_upper(av[1][i]))
				c = av[1][i] - 'A';
			if ((is_lower(av[1][i]) || is_upper(av[1][i])) && vis[(int)c])
			{
				if (k == count - 1)
				{
					fn(vis[(int)c]);
					f(c + 'a');
					vis[(int)c] = 0;
				}
				else if (k < count)
				{
					fn(vis[(int)c]);
					f(c + 'a');
					write(1, ", ", 2);
					vis[(int)c] = 0;
					k++;
				}
			}
			i++;
		}
	}
	f('\n');
	return 0;
}
















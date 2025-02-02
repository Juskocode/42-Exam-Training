#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	fl(char c){return (c >= 'a' && c <= 'z');}
int	fup(char c){return (c >= 'A' && c <= 'Z');}

int	fb(char c){return (c == ' ' || c == '\t');}

void	ft_rcap(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (fup(s[i]))
			s[i] += 32;
		if ((fb(s[i + 1]) || !s[i + 1]) && fl(s[i]))
			s[i] -= 32;
		f(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			ft_rcap(av[i]);
			f('\n');
			i++;
		}
		return 0;
	}
	f('\n');
	return 0;
}

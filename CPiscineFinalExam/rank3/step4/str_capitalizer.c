#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	fb(char c){return c == ' ' || c == '\t';}
int	fup(char c){return c >= 'A' && c <= 'Z';}
int	flw(char c){return c >= 'a' && c <= 'z';}

void	ft_strcap(char *s)
{
	int i = 0;
	while (s[i])
	{
		while (fb(s[i]))
		{
			f(s[i]);
			i++;
		}
		//first char of word if lowcase cap that shit up
		if (s[i])
		{
			if (flw(s[i]))
			{
				s[i] -= 32;
				f(s[i]);
				i++;
			}
			else
			{
				f(s[i]);
				i++;
			}
		}
		while (!fb(s[i]) && s[i])
		{
			if (fup(s[i]))
			{
				s[i] += 32;
				f(s[i]);
			}
			else
				f(s[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			ft_strcap(av[i]);
			f('\n');
			i++;
		}
		return 0;
	}
	f('\n');
	return 0;
}

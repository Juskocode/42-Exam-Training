#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

void	fs(const char *s){if (!s) return ; f(*s); fs(++s);}

void	str_cap(const char *s)
{
	int i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
		{
			f(s[i]);
			i++;
		}
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			f(s[i] - 32);
			i++;
		}
		else
			f(s[i++]);
		while (s[i] != ' ' && s[i])
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				f(s[i] + 32);
			else	
				f(s[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)	
		{
			str_cap(av[i]);
			f('\n');
		}
		f('\n');
	}
	return 0;
}

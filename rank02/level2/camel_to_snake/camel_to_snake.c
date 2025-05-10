#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

void	ft_camel_to_snake(const char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			f('_');
			f(s[i] + 32);
		}
		else
			f(s[i]);
	}
}

void	ft_snake_to_camel(const char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '_')
		{
			f(s[i + 1] - 32);
			i++;	
		}
		else
			f(s[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_camel_to_snake(av[1]);
		f('\n');
		ft_snake_to_camel(av[2]);
	}
	f('\n');
	return 0;
}

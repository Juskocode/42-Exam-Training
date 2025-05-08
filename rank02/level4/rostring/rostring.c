#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

void	fs(const char *s){if (!s)return ;f(*s);fs(++s);}

int	fslen(const char *s){if (!s)return 0;return 1 + fslen(++s);}

void	rotation_maluca(const char *words)
{
	int i = 0, j = 0, k = 0;
	while (words[i] == ' ')
		i++;
	k = i;
	while (words[i] && words[i] != ' ')
		i++;
	j = i;
	while (words[i])
	{
		while (words[i] == ' ')
			i++;
		while (words[i] != ' ' && words[i])
			f(words[i++]);
		if (words[i])
			f(' ');
	}
	while (k < j)
	{
		f(words[k]);
		k++;
	}
}

int	main(int ac, char** av)
{
	if (ac == 2)
	{
		rotation_maluca(av[1]);
		f('\n');
	}
	return 0;
}

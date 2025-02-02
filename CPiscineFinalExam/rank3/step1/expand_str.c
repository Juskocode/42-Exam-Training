#include <unistd.h>

void	f(char c){write(1, &c, 1);}

int	fb(char c){return c == ' ' || c == '\t';}

void	ft_expand(char *s)
{
	int i = 0;
	//skip first blanks to change the instructions order on the loop
	//this way we read nchar then skip blank in the end if
	//the string ends we dont print 3 spaces
	//this was done to do this in a single loop
	//outperforming most of you noobs lol
	while (fb(s[i]))
		i++;
	while (s[i])
	{
		while (!fb(s[i]) && s[i])
		{
			f(s[i]);
			i++;
		}
		while (fb(s[i]))
			i++;
		//only print space if not at last
		if (s[i])
			write(1, "   ", 3);
	}
}

int	main(int ac, char **av)
{	
	if (ac == 2)
	{
		ft_expand(av[1]);
	}
	f('\n');
	return 0;
}

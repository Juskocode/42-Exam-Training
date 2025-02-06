#include <unistd.h>

void	f(char c)
{
	write(1, &c, 1);
}

void	fs(char *str)
{
	int i = 0;
	while (str[i])
	{
		f(str[i]);
		i++;
	}
}

//skip whitespaces
//process sign
//process numbers
int	ft_atoi(char *s)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;

	while(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if(s[i] == '-' && s[i] == '+')
	{
	      if(s[i] == '-')
		      sign = sign * -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
 		result = result * 10 + (s[i] - '0');
		i++;
	}
	return(result * sign);	
}


int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int idx = ft_atoi(av[ac - 1]);
		if (idx < 1 || idx >= ac)
		{
			f('\n');
			return 0;
		}
		fs(av[idx]);
	}
	f('\n');
	return 0;
}

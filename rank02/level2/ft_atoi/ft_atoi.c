#include <unistd.h>

int	ft_atoi(const char *str)
{
	int i = 0, s = 1, n = 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s =-s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n += str[i] + '0';
		n *= 10;
		i++;
	}
	return n*s;
}

int	fb(char c){return c <= 32;}

//As we want to process any base
//and actually check for low and uppercase bro
//just chill, sit up and relax
//i have your solution here
//by building an arrays for upper and lower we check
//for 2fFaA for example
int	ft_valid_d(char c, int base)
{
	char digl[] = "0123456789abcdef";
	char digu[] = "0123456789ABCDEF";

	int i = 0;
	while (i < base)
	{
		if (digl[i] == c || digu[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int	ft_compute_val(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'Z')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	return 0;
}

//same as normal atoi lmao
int	ft_atoi_base(const char *str, int str_base)
{

	int sign = 1, res = 0;

	//skip blanks
	while (fb(*str))
		str++;
	//process a single '-'
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	//same as normal atoi bro EZZZ
	while (ft_valid_d(*str, str_base))
		res = res * str_base  + ft_compute_val(*str++);
	return res * sign;
}

//Super megalazanga main to test any value ez
//identation ultra pro max certificatied!!
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int base = atoi(av[2]);
		printf("base: %d \tnumber: %s\nbase: 10\tnumber: %d\n",base, av[1], ft_atoi_base(av[1], base));
	}
	return 0;
}

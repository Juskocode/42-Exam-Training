#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_gcd(unsigned int a, unsigned int b)
{
	if (!b)
		return a;
	return ft_gcd(b, a % b);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return 0;
	return (a * b) / ft_gcd(a, b);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d", lcm(atoi(av[1]), atoi(av[2])));
	}
	printf("\n");
	return 0;
}

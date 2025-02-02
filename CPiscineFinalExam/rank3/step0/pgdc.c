#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int a)
{
	return (a < 0) ? -a : a;
}

int	ft_gcd(int a, int b)
{
	if (!b)
		return a;
	return ft_gcd(b, a % b);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int a = atoi(av[1]), b = atoi(av[2]);
		printf("%d", ft_abs(ft_gcd(a, b)));
	}
	printf("\n");
	return 0;

}


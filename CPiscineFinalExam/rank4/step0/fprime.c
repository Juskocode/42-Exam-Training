#include <stdlib.h>
#include <stdio.h>

int	ft_is_prime(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i*i <=n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void	ft_print_fprime(int n)
{
	int p = 2;
	while (n != 1)
	{
		while (n % p == 0)
		{
			if (n / p > 1)
				printf("%d*", p);
			else
				printf("%d", p);
			n /= p;
		}
		p++;
		while (!ft_is_prime(p)) p++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_print_fprime(atoi(av[1]));
	}
	printf("\n");
	return 0;
}

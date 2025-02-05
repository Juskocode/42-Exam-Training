#include <stdlib.h>
#include <stdio.h>

//we don't need to check for 
//primes just use the sive of erastothenes
//EZ
void	ft_print_fprime(int n)
{
	if (n < 2)
	{
		printf("%d", n);
		return ;
	}
	//quick check for even numbers
	//this can bypass large even numbers
	while (!(n & 1))
	{
		printf("2");
		n >>= 1;
	}
	//odd case 
	//sieve applyed
	//go until sqrt(n) skip 2 by 2
	for (int i = 3; i*i <= n; i += 2)
	{
		while (n % i == 0)
		{
			if (n / i > 1)
				printf("%d*", i);
			else
				printf("%d", i);
			n /= i;
		}
	}
	//edge case for prime
	if (n > 2)
		printf("%d", n);

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

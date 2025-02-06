#include <stdlib.h>
#include <stdio.h>

int	ft_len(long n)
{
	int count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return count;
}

char	*ft_itoa(int nbr)
{
	long nb = nbr;
	int len = ft_len(nb), i = 0;
	char *n;

	n = (nb > 0) ? malloc(len + 1) : malloc(len + 2);
	if (!n)
		return 0;
	i = (nb > 0) ? len : len + 1;
	if (nb < 0)
	{
		nb = -nb;
		n[0] = '-';
	}
	n[i--] = 0;
	while (nb)
	{
		n[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return n;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s\n", ft_itoa(atoi(av[1])));
	}
	return 0;
}

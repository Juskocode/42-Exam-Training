#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	unsigned int size = 0, i = 0;
	int nbr_ = nbr;
	while (nbr_)
	{
		nbr_ /= 10;
		size++;
	}
	char *res = (nbr > 0) ? malloc(size + 1) : malloc(++size + 1);
	printf("size : %d \n", size + 1);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[size] = 0;
	while (i < size)
	{
		res[size - i - 1] = (nbr % 10) + '0';
		printf("[%d]: %s \n", i, (res + size - i - 1));
		nbr /= 10;
		i++;
	}
	return res;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int a = atoi(av[1]);
		char *s = ft_itoa(a);
		printf("final: %s", s);
	}
	printf("\n");
	return 0;
}

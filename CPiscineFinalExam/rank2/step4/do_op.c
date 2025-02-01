#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int a = atoi(av[1]), b = atoi(av[3]);
		char op = *av[2];
		if (op == '+')
			printf("%d", a + b);
		else if (op == '-')
			printf("%d", a - b);
		else if (op == '*')
			printf("%d", a * b);
		else if (op == '/' && b)
			printf("%d", a / b);
		else if (op == '%' && b)
			printf("%d", a % b);
	}
	printf("\n");
	return 0;
}

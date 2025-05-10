#include <unistd.h>
#include <stdlib.h>

int	ft_abs(int a)
{
	return (a > 0) ? a : -a;
}

int*	ft_xrange(int start, int end)
{
	int size = ft_abs(end - start) + 1;
	int* r = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		r[i] = end + ((end < start) ? i : -i);
	return r;
}

#include <stdio.h>

int	main(void)
{
	int s = -2, e = 3;
	int *r = ft_xrange(-2, 3);
	for (int i = 0; i < 6; i++)
		printf("%d ", r[i]);
	printf("\n");
	free(r);
	return 0;
}

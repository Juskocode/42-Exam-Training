#include <stdlib.h>

int	f_abs(int a){return (a < 0) ? -a : a;}

int	*ft_range(int start, int end)
{
	int len = f_abs(start - end) + 1, sign = 1;
	if (start > end)
		sign = -sign;
	int *range = malloc(4 * len);
	if (!range)
		return 0;
	int i = 0;
	while (i < len)
	{
		range[i] = start + (i * sign);
		i++;
	}
	return range;
}

#include <stdio.h>

int	main(void)
{
	int *v1, *v2, *v3, *v4;
	v1 = ft_range(1, 3);
	v2 = ft_range(-1, 2);
	v3 = ft_range(0, 0);
	v4 = ft_range(0, -3);
	for (int i = 0; i < 3; i++)
		printf("%d ", v1[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("%d ", v2[i]);
	printf("\n");
	for (int i = 0; i < 1; i++)
		printf("%d ", v3[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("%d ", v4[i]);
	printf("\n");
	return 0;
}

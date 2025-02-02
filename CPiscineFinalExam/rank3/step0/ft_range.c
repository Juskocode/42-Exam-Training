#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}

int	*ft_range(int start, int end)
{
	int si = 1, len = 0;
	if (start > end)
		si = -si;
	len = ft_abs(start - end) + 1;
	int *range = malloc(sizeof(int) * len);
	if (!range)
		return 0;
	int i = 0;
	while (i < len)
	{
		range[i] = end - (i * si);
		i++;	
	}
	return range;
}

int	main(void)
{
	int	*v1, *v2, *v3, *v4;
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
	free(v1);
	free(v2);	
	free(v3);	
	free(v4);
	return 0;
}

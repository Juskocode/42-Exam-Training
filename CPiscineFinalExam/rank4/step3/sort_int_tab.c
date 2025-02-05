#include <stdio.h>

void	ft_sort_int_tab(int *tab, unsigned int size)
{
		for (unsigned int i = 0; i < size; i++)
		{
			for (unsigned int j = i + 1; j < size; j++)
			{
				if (tab[i] > tab[j])
				{
					int t = tab[i];
					tab[i] = tab[j];
					tab[j] = t;
				}
			}
		}
}

int	main(void)
{
	int arr [5] = {2, 4, 1, -10, 4};
	ft_sort_int_tab(arr, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

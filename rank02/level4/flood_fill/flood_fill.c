#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

void	dfs(int x, int y, char **tab, t_point size, const char target)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y || tab[y][x] != target)
		return ;
	tab[y][x] = 'F';

	dfs(x + 1, y, tab, size, target);
	dfs(x - 1, y, tab, size, target);
	dfs(x, y + 1, tab, size, target);
	dfs(x, y - 1, tab, size, target);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	dfs(begin.x, begin.y, tab, size, target);
}

void	print_tab(char **mat, t_point size)
{
	for (int i = 0; i < size.y; i++)
	{
		printf("%s", mat[i]);
		printf("\n");
	}
}

int main(void)
{
    t_point size = {8, 5};
    t_point begin = {2, 2};
    // Create modifiable copies of each row
    char *area[] = {
        strdup("11111111"),
        strdup("10001001"),
        strdup("10010001"),
        strdup("10110001"),
        strdup("11100001"),
    };
    // Check for allocation errors (omitted here for brevity)
    
    print_tab(area, size);
    flood_fill(area, size, begin);
    printf("\n");
    print_tab(area, size);
    
    // Free allocated memory
    for (int i = 0; i < size.y; i++)
        free(area[i]);
    return (0);
}

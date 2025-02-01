#include <stdlib.h>

int	ft_strlen(char *s1)
{
	int	i = 0;
	while (s1[i])
		i++;
	return i;
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int	size;

	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size);
	if (!dup)
		return 0;
	dup = ft_strcpy(dup, s);
	sup[size] = 0;
	return (dup);
}

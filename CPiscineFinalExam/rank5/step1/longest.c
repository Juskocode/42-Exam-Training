#include <stdlib.h>
#include <unistd.h>

int	ft_common_len(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return i;
}

char	*ft_strdupn(char *s1, int n)
{
	char *dup = malloc(n + 1);
	if (!dup)
		return 0;
	int i = 0;
	while(i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[n] = 0;
	return dup;
}

char	*find_longest_common(char *s1, char *s2)
{
	char *res = NULL;
	char *p1 = s1;
	char *p2 = s2;
	int max_val = 0;

	while (*p1)
	{
		p2 = s2;
		while (*p2)
		{
			int curr = ft_common_len(p1, p2);
			if (curr > max_val)
			{
				max_val = curr;
				free(res);
				res = ft_strdupn(p2, max_val);
			}
			p2++;
		}
		p1++;
	}
	return res;
}

int	get_longest_c_all(int ac, char **av)
{
	char *ret = find_longest_common(av[1], av[2]);
	if (!ret)
		return 0;
	int i = 3;
	while (i < ac)
	{
		char* t = find_longest_common(ret, av[i]);
		free(ret);
		ret = t;
		if (!ret)
			return 0;
		i++;
	}
	i = 0;
	while (ret[i])
	{
		write(1, &ret[i], 1);
		i++;
	}
	free(ret);
	return 0;
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		get_longest_c_all(ac, av);
	}
	write(1, "\n", 1);
}













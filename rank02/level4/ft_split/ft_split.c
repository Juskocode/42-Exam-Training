#include <unistd.h>
#include <stdlib.h>

int	ft_is_sep(char c, char *sep)
{
	for (int i = 0; sep[i]; i++)
	{
		if (c == sep[i])
			return 1;
	}
	return 0;
}

int	ft_count_words(char *s, char *sep)
{
	int i = 0, count = 0;
	while (s[i])
	{
		while (ft_is_sep(s[i], sep))
			i++;
		if (s[i])
			count++;
		while (!ft_is_sep(s[i], sep) && s[i])
			i++;
	}
	return count;
}

int	ft_len_to_sep(char *s, char *sep)
{
	int i = 0;
	while (s[i] && !ft_is_sep(s[i], sep))
		i++;
	return i;
}

char*	ft_strdup(char *s, char *sep)
{
	size_t ds = ft_len_to_sep(s, sep);
	char *d = (char * )malloc(sizeof(char) * (ds + 1));
	if (!d)
		return NULL;
	for (int i = 0; i < ds; i++)
		d[i] = s[i];
	d[ds] = 0;
	return d;
}

char**	ft_split(char* s, char *sep)
{
	int i = 0, size = ft_count_words(s, sep), k = 0;
	char** words = (char **)malloc(sizeof(char* ) * (size + 1));
	if (!words)
		return NULL;
	while (s[i])
	{
		while (ft_is_sep(s[i], sep))
			i++;
		if (s[i])
		{
			words[k++] = ft_strdup(s + i, sep);
		}
		i += ft_len_to_sep(s + i, sep);
	}
	words[k] = NULL;
	return words;
}

#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *sep = " .-";
		char **words = ft_split(av[1], sep);
		int len = ft_count_words(av[1], sep);
		for (int i = 0; i < len; i++)
		{
			printf("%s\n", words[i]);
			free(words[i]);
		}
		free(words);
	}
	return 0;
}

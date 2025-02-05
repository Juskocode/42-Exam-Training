#include <stdlib.h>
#include <stdio.h>

//This is the final boss of some pisciners
//This is Not a Tutorial WARNING!
//THIS IS THE REAL DEAL
//DEAL WITH IT BRO!
//IT'S EZZ JUST KIDDING
//JUST FOLLOW ALONG DUDE XD
//check if it's not word lol
int	ft_is_sep(char c){return c == ' ' || c == '\t' || c == '\n';}

//this just gives me the current word size
unsigned int	ft_size_word(char *s)
{
	unsigned int i = 0;
	while (!ft_is_sep(s[i]) && s[i])
		i++;
	return i;
}

//compute the total words
size_t	ft_count_words(char *s)
{
	size_t i = 0, count = 0;
	while (s[i])
	{
		while (ft_is_sep(s[i]))
			i++;
		if (s[i])
			count++;
		while (!ft_is_sep(s[i]) && s[i])
			i++;
	}
	return count;
}

// i like to use strncpy here
// my s1 (dest) is always n bytes no padding needed
char	*ft_strncpy(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return s1;
}

//strDUPLICATORRR
char	*ft_strdup(char *s)
{
	unsigned int size = ft_size_word(s);
	char *dup = malloc(size + 1);
	if (!dup)
		return 0;
	dup = ft_strncpy(dup, s, size);
	return dup;
}

//splitadeiro 
char	**ft_split(char *str)
{
	int k = 0, size = ft_count_words(str);
	char **words = malloc(sizeof(char *) * size + 1);
	
	while (*str)
	{
		while (ft_is_sep(*str))
			str++;
		if (*str)
		{
			words[k++] = ft_strdup(str);
		}
		while (!ft_is_sep(*str) && *str)
			str++;
	}
	words[k] = 0;
	return words;
}

int	main(void)
{
	char s[] = "ana ola\nbanana\t\njoana 1 2 3";
	int size = ft_count_words(s);
	char **words = ft_split(s);
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
}

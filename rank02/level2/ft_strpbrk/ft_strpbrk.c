#include <stdlib.h>
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	char table[257] = {0};
	for (; *s2; s2++) table[(unsigned char)*s2] = 1;
	for (; *s1; s1++) if (table[(unsigned char)*s1]) return (char *)(s1);
	return NULL;
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = strdup("aaaa'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.bbbbbbbbbbbbbbbbbbb.ccc1234567890dddd-ssss.-+wwww");
	char *sep = strdup("1234567890,.-+'");
	char *s1_ = s1;

	int count = 0;
	while (*s1)
	{
		count++;
		s1 = ft_strpbrk(s1, sep);
		if (!s1) break;
		printf("Occurance %d :  %s \n", count, s1);
//		char c;
//		scanf("%c", &c);
		s1++;
	}
	free(s1_);
	free(sep);
	return 0;
}

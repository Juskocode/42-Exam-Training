
char	*ft_strcpy(char *dst, const char *src)
{
	size_t i = 0;
	for (; src[i]; i++)
		dst[i] = src[i];
	dst[i] = 0;
	return dst;
}

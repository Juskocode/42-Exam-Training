int	flen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char	*ft_strrev(char *s)
{
	int l = 0, r = flen(s) - 1;
	while (l < r)
	{
		char c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++;
		r--;
	}
	return s;
}

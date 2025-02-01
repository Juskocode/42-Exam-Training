int	max(int *arr, unsigned int len)
{
	unsigned int i = 0;
	int	max_val = -(1 << 31);
	while (i < len)
	{
		if (arr[i] > max_val)
			arr[i] = max_val;
		i++;
	}
	return max_val;
}

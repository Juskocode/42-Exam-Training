int	is_power_of_2(unsigned int n)
{
	//bro just check the pop_count if it's you fine bro!
	//the pop_count is the number of 1's on the number binary representation
	//the logic is simple if more than one bit is set
	//the number can no longer be a power of 2
	//why?
	//simple
	//think, 0001 = 1 (2^0), 0010 = 2 (2^1) and so on...
	//1111 well funny story it will ne 2^4 - 1 (16)
	//lol the sum of all powers of 2 until n is 2^(n+1) - 1
	//so yeah pretty much it bros xD
	//if not return 0 lmao
	int	count = 0; 
	for (int i = 0; i < 32; i++)
	{
		if (n & 1)
			count++;
		if (count > 1)
			return 0;
		n >>= 1;
	}
	return (count == 1); //case if n is 0
}

#include <stdio.h>

int	main(void)
{
	int v = 0;
	while (v != -1)
	{
		scanf("%d\n", &v);
		if (is_power_of_2(v))
			printf("%d is a power of 2!", v);
		else
			printf("%d lame not a power of 2 :(", v);
	}
	return 0;
}

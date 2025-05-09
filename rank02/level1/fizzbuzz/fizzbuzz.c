#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

void	fn(unsigned int n)
{
	if (n < 10)
	{
		f(n + '0');
		return ;
	}
	fn(n / 10);
	fn(n % 10);
}

void	fzbz()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			fn(i);
		f('\n');
	}
}

int	main(void)
{
	fzbz();
	return 0;
}

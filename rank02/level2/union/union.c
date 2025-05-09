#include <unistd.h>

void	f(const char c){write(1, &c, 1);}

void	intersection(const char* a, const char* b)
{
	char vis[127] = {0};

	for (int i = 0; a[i]; i++)
	{
		const unsigned int c = a[i];
		vis[c] = 1;
	}
	for (int i = 0; b[i]; i++)
	{
		const unsigned int c = b[i];
		if (vis[c])
		{
			f(b[i]);
			vis[c] = 0;
		}
	}	
}

void	union_(const char* a, const char* b)
{
	char vis[127] = {0};

	for (int i = 0; a[i]; i++)
	{
		const unsigned int c = a[i];
		if (!vis[c])
		{	
			vis[c] = 1;
			f(a[i]);
		}
	}
	for (int i = 0; b[i]; i++)
	{
		const unsigned int c = b[i];
		if (!vis[c])
		{
			f(b[i]);
			vis[c] = 1;
		}
	}	
}

int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		write(1, "a ^ b :", 7);
		intersection(av[1], av[2]);
		f('\n');
		write(1, "a v b :", 7);
		union_(av[1], av[2]);	
	}
	f('\n');
	return 0;
}

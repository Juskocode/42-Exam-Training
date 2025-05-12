#include <unistd.h>

unsigned int	ft_atoui(const char *s)
{
	unsigned int n = 0, i = 0;
	while (s[i] >= 9 && s[i] <= 13 || s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += (s[i] - '0');
		i++;
	}
	return n;
}

void	ft_print_c(const char c){write(1, &c, 1);}

void	ft_print_s(const char *s){if (!*s) return ; ft_print_c(*s); ft_print_s(++s);}

void	ft_print_ui(unsigned int n)
{
	if (n < 10)
		ft_print_c(n + '0');
	else
	{
		ft_print_ui(n / 10);
		ft_print_ui(n % 10);
	}
}

int	is_p2(unsigned int n)
{
	if (!n)
		return n;
	return (n & -n) == n;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		unsigned int a = ft_atoui(av[1]);
		if (is_p2(a))
			ft_print_s(" is a power of 2");
		else
			ft_print_s(" is not a power of 2");
	}
	ft_print_c('\n');
	return 0;
}

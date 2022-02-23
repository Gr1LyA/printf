#include "ftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putstr("-");
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

void	ft_putstr_len(char *s, int len)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0' && i < len)
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	ft_atoi1(char *str, int len)
{
	int		res;
	int		znak;
	int		i;

	znak = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		znak *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && i <= len)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * znak);
}

int	ft_len_num(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (++i);
}

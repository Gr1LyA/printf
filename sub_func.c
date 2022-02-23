#include "ftprintf.h"

char	*base_mass(char flag)
{
	char		*base;

	if (flag == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base);
}

void	sixteen_recursive(unsigned long num, char flag, char *base)
{
	if (num)
	{
		sixteen_recursive(num >> 4, flag, base);
		ft_putchar(base[num % 16]);
	}
}

void	sixteen(unsigned long num, char flag)
{
	char		*base;

	base = base_mass(flag);
	if (flag == 'p')
		write(1, "0x", 2);
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	sixteen_recursive(num, flag, base);
	if (num == 0)
		ft_putchar('0');
}

void	mass_spec(char flag, int width)
{
	int		i;

	i = 0;
	if (flag == '0')
	{
		while (i < width)
		{
			i++;
			ft_putchar('0');
		}
	}
	else
	{
		while (i < width)
		{
			i++;
			ft_putchar(' ');
		}
	}
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

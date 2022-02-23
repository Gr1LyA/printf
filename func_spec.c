#include "ftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	spec_p(t_pars pars, unsigned long num)
{
	int	len;

	len = len_sixteen(num) + 2;
	if (pars.width > len)
	{
		if (pars.flag == '-')
		{
			sixteen(num, pars.spec);
			mass_spec(pars.flag, pars.width - len);
		}
		else
		{
			mass_spec(pars.flag, pars.width - len);
			sixteen(num, pars.spec);
		}
		return (pars.width);
	}
	sixteen(num, pars.spec);
	return (len);
}

int	sub_spec_s(t_pars pars, int len)
{
	if (pars.precision > len && pars.width > pars.precision)
		return (pars.width);
	else if (pars.width > len)
		return (pars.width);
	return (len);
}

int	spec_percent(t_pars pars)
{
	if (pars.flag == '-')
	{
		ft_putchar('%');
		mass_spec(pars.flag, pars.width - 1);
	}
	else
	{
		mass_spec(pars.flag, pars.width - 1);
		ft_putchar('%');
	}
	if (pars.width > 1)
		return (pars.width);
	return (1);
}

int	len_sixteen(unsigned long num)
{
	int	i;

	i = 0;
	while (num || i == 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

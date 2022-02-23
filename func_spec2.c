#include "ftprintf.h"

void	sub_spec_x(t_pars pars, unsigned int num, int len)
{
	if (pars.flag == '-')
	{
		mass_spec('0', pars.precision - len);
		sixteen(num, pars.spec);
		mass_spec('+', pars.width - pars.precision);
	}
	else
	{
		mass_spec('+', pars.width - pars.precision);
		mass_spec('0', pars.precision - len);
		sixteen(num, pars.spec);
	}
}

void	sub2_spec_x(t_pars pars, unsigned int num, int len)
{
	if (pars.precision != -1 && pars.flag == '0')
		pars.flag = '+';
	if (pars.flag != '-')
	{
		mass_spec(pars.flag, pars.width - len);
		sixteen(num, pars.spec);
	}
	else
	{
		sixteen(num, pars.spec);
		mass_spec(pars.flag, pars.width - len);
	}
}

int	spec_x(t_pars pars, unsigned int num)
{
	int		len;

	len = len_sixteen(num);
	if (pars.precision == 0 && num == 0)
	{
		mass_spec(' ', pars.width);
		return (pars.width);
	}
	if (len < pars.precision)
		sub_spec_x(pars, num, len);
	else
		sub2_spec_x(pars, num, len);
	if (pars.precision >= len && pars.width >= pars.precision)
		return (pars.width);
	else if (pars.precision >= len)
		return (pars.precision);
	else if (pars.width >= len)
		return (pars.width);
	return (len);
}

int	spec_c(char symbol, int width, char flag)
{
	if (flag == '-')
	{
		ft_putchar(symbol);
		mass_spec(flag, width - 1);
	}
	else
	{
		mass_spec(flag, width - 1);
		ft_putchar(symbol);
	}
	if (width != 0)
		return (width);
	return (1);
}

int	spec_s(t_pars pars, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len > pars.precision && pars.precision != -1)
		len = pars.precision;
	if (pars.width > len)
	{
		if (pars.flag == '-')
		{
			ft_putstr_len(str, len);
			mass_spec(pars.flag, pars.width - len);
		}
		else
		{
			mass_spec(pars.flag, pars.width - len);
			ft_putstr_len(str, len);
		}
		return (pars.width);
	}
	ft_putstr_len(str, len);
	return (sub_spec_s(pars, len));
}

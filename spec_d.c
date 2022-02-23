#include "ftprintf.h"

void	sub4_spec_d(t_pars pars, long num, int len)
{
	if (num < 0)
	{
		len--;
		num *= -1;
		if (pars.flag != '-')
		{
			mass_spec('+', pars.width - pars.precision - 1);
			ft_putchar('-');
			mass_spec('0', pars.precision - len);
			ft_putnbr(num);
			return ;
		}
		ft_putchar('-');
		mass_spec('0', pars.precision - len);
		ft_putnbr(num);
		mass_spec('+', pars.width - pars.precision - 1);
		return ;
	}
	mass_spec('+', pars.width - pars.precision);
	mass_spec('0', pars.precision - len);
	ft_putnbr(num);
}

void	sub_spec_d(t_pars pars, long num, int len)
{
	if (pars.flag == '-' && num >= 0)
	{
		mass_spec('0', pars.precision - len);
		ft_putnbr(num);
		mass_spec('+', pars.width - pars.precision);
	}
	else
		sub4_spec_d(pars, num, len);
}

void	sub2_spec_d(t_pars pars, long num, int len)
{
	if (pars.precision != -1 && pars.flag == '0')
		pars.flag = '+';
	if (pars.flag != '-')
	{
		if (num < 0 && pars.flag == '0')
		{
			ft_putchar('-');
			mass_spec('0', pars.width - len);
			ft_putnbr(num * -1);
			return ;
		}
		mass_spec(pars.flag, pars.width - len);
		ft_putnbr(num);
	}
	else
	{
		ft_putnbr(num);
		mass_spec(pars.flag, pars.width - len);
	}
}

int	sub3_spec_d(t_pars pars, long num, int len)
{
	if (pars.precision >= len && pars.width >= pars.precision)
	{
		if (num < 0 && pars.width <= pars.precision)
			pars.width++;
		return (pars.width);
	}
	else if (pars.precision >= len)
	{
		if (num < 0)
			pars.precision++;
		return (pars.precision);
	}
	else if (pars.width >= len)
		return (pars.width);
	return (len);
}

int	spec_d(t_pars pars, long num)
{
	int		len;

	len = ft_len_num(num);
	if (pars.precision == 0 && num == 0)
	{
		mass_spec(' ', pars.width);
		return (pars.width);
	}
	if (len < pars.precision)
		sub_spec_d(pars, num, len);
	else if (num < 0 && pars.precision > len - 1)
	{
		ft_putchar('-');
		mass_spec('0', pars.precision - len + 1);
		ft_putnbr(num * -1);
		return (pars.precision + 1);
	}
	else
		sub2_spec_d(pars, num, len);
	return (sub3_spec_d(pars, num, len));
}

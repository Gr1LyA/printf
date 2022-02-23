#include "ftprintf.h"

int	printin(t_pars pars, va_list ap)
{
	if (pars.spec == 'c')
		return (spec_c(va_arg(ap, unsigned int), pars.width, pars.flag));
	else if (pars.spec == 's')
		return (spec_s(pars, va_arg(ap, char *)));
	else if (pars.spec == 'x' || pars.spec == 'X')
		return (spec_x(pars, va_arg(ap, unsigned int)));
	else if (pars.spec == 'p')
		return (spec_p(pars, va_arg(ap, unsigned long)));
	else if (pars.spec == 'd' || pars.spec == 'i')
		return (spec_d(pars, va_arg(ap, int)));
	else if (pars.spec == 'u')
		return (spec_d(pars, va_arg(ap, unsigned int)));
	else
		return (spec_percent(pars));
}

t_pars	sub_parser(char *str, int len, t_pars pars, va_list ap)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		pars.precision = 0;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		j = i;
		while (str[i] >= '0' && str[i] <= '9' && i <= len)
			i++;
		pars.precision = ft_atoi1(str + j, i - j);
	}
	else if (str[i] == '*')
	{
		pars.precision = va_arg(ap, int);
		if (pars.precision < 0)
			pars.precision = -1;
		i++;
	}
	pars.spec = str[i];
	return (pars);
}

t_pars	sub_sub_parser(char *str, int len, t_pars pars, va_list ap)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		j = i;
		while (str[i] >= '0' && str[i] <= '9' && i <= len)
			i++;
		pars.width = ft_atoi1(str + j, i - j);
	}
	else if (str[i] == '*')
	{
		pars.width = va_arg(ap, int);
		if (pars.width < 0)
		{
			pars.flag = '-';
			pars.width *= -1;
		}
		i++;
	}
	return (sub_parser(str + i, len, pars, ap));
}

int	parser(char *str, int len, va_list ap)
{
	t_pars	pars;
	int		i;

	pars.width = 0;
	pars.precision = -1;
	pars.flag = '+';
	i = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		pars.flag = str[i++];
		if (pars.flag == '-')
		{
			while (str[i] == '0' || str[i] == '-')
				i++;
		}
	}
	pars = sub_sub_parser(str + i, len, pars, ap);
	return (printin(pars, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*start;
	int		i;

	i = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			start = (char *)++format;
			while (*format != 'c' && *format != 's' && *format != 'p'
				&& *format != 'd' && *format != 'i' && *format != 'u'
				&& *format != 'x' && *format != 'X' && *format != '%')
				format++;
			i = i + parser(start, format - start + 1, ap) - 1;
		}
		else
			ft_putchar(*format);
		format++;
		i++;
	}
	va_end(ap);
	return (i);
}

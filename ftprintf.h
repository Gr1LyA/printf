#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_pars
{
	char		flag;
	char		spec;
	int			width;
	int			precision;
}				t_pars;

char	*base_mass(char flag);
void	sixteen(unsigned long num, char flag);
int		ft_len_num(long int n);
void	mass_spec(char flag, int width);
int		sub_spec_s(t_pars pars, int len);
int		spec_s(t_pars pars, char *str);
int		spec_c(char symbol, int width, char flag);
void	sub_spec_x(t_pars pars, unsigned int num, int len);
void	sub2_spec_x(t_pars pars, unsigned int num, int len);
int		spec_x(t_pars pars, unsigned int num);
int		spec_p(t_pars pars, unsigned long num);
void	sub_spec_d(t_pars pars, long num, int len);
void	sub2_spec_d(t_pars pars, long num, int len);
int		spec_d(t_pars pars,	long num);
int		printin(t_pars pars, va_list ap);
t_pars	sub_parser(char *str, int len, t_pars pars, va_list ap);
int		parser(char *str, int len, va_list ap);
int		ft_printf(const char *format, ...);
int		spec_percent(t_pars pars);
int		sub3_spec_d(t_pars pars, long num, int len);
void	ft_putchar(char c);
void	ft_putnbr(long n);
void	ft_putstr_len(char *s, int len);
int		ft_atoi1(char *str, int len);
int		ft_len_num(long int n);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		len_sixteen(unsigned long num);

#endif
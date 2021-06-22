#include "ft_printf.h"

void	ft_shirina(t_printf *s_printf, const char **str, va_list factor)
{
	if (**str == '*')
	{
		s_printf->flag_shirina_len = va_arg(factor, int);
		if (s_printf->flag_shirina_len < 0)
		{
			s_printf->flag_minus = 1;
			s_printf->flag_zero = 0;
			s_printf->flag_shirina_len = -s_printf->flag_shirina_len;
		}
		(*str)++;
	}
	else if (**str >= '0' && **str <= '9')
	{
		s_printf->flag_shirina_len = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}

void	ft_tochnost(t_printf *s_printf, const char **str, va_list factor)
{
	if (**str == '.')
	{
		s_printf->flag_tochnost = 1;
		(*str)++;
	}
	if (**str == '*')
	{
		s_printf->flag_tochnost_len = va_arg(factor, int);
		if (s_printf->flag_tochnost_len < 0)
		{
			s_printf->flag_tochnost = 0;
			s_printf->flag_tochnost_len = -1;
		}
		(*str)++;
	}
	else if (**str >= '0' && **str <= '9')
	{
		s_printf->flag_tochnost_len = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}

void	ft_types_dics(t_printf *s_printf, const char **str, va_list factor)
{
	if (**str == 'd' || **str == 'i')
	{
		s_printf->flag_type_di = 1;
		s_printf->flag_base = 10;
		s_printf->flag_type_znach = va_arg(factor, int);
	}
	if (**str == 'c')
	{
		s_printf->flag_type_c = 1;
		s_printf->flag_c_znach = va_arg(factor, int);
	}
	if (**str == 's')
	{
		s_printf->flag_type_s = 1;
		s_printf->flag_s_znach = va_arg(factor, char *);
	}
}

void	ft_types_uxp(t_printf *s_printf, const char **str, va_list factor)
{
	if (**str == 'u')
	{
		s_printf->flag_type_u = 1;
		s_printf->flag_base = 10;
		s_printf->flag_type_znach = va_arg(factor, unsigned int);
	}
	if (**str == 'x' || **str == 'X')
	{
		if (**str == 'x')
			s_printf->flag_type_x_l = 1;
		else
			s_printf->flag_type_x_b = 1;
		s_printf->flag_base = 16;
		s_printf->flag_type_znach = va_arg(factor, unsigned int);
	}
	if (**str == 'p')
	{
		s_printf->flag_type_p = 1;
		s_printf->flag_type_x_l = 1;
		s_printf->flag_base = 16;
		s_printf->flag_type_znach = va_arg(factor, long long int);
	}
}

char	*ft_specificator(const char *str, t_printf *s_printf, va_list factor)
{
	while (*str++)
	{
		if (*str == '0')
		{
			s_printf->flag_zero = 1;
			continue ;
		}
		if (*str == '-')
		{
			s_printf->flag_minus = 1;
			s_printf->flag_zero = 0;
			continue ;
		}
		ft_shirina(s_printf, &str, factor);
		ft_tochnost(s_printf, &str, factor);
		ft_types_dics(s_printf, &str, factor);
		ft_types_uxp(s_printf, &str, factor);
		if (*str == '%')
			s_printf->flag_type_percent = 1;
		break ;
	}
	return ((char *)str);
}

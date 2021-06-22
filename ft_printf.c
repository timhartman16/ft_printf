#include "ft_printf.h"

void	ft_type_print(t_printf *print, int *length)
{
	if (print->flag_type_di)
		*length += ft_print_int(print);
	if (print->flag_type_c)
		*length += ft_print_char(print);
	if (print->flag_type_s)
		*length += ft_print_string(print);
	if (print->flag_type_u)
		*length += ft_print_int(print);
	if (print->flag_type_x_l && print->flag_type_p == 0)
		*length += ft_print_int(print);
	if (print->flag_type_x_b)
		*length += ft_print_int(print);
	if (print->flag_type_p && print->flag_type_x_l)
		*length += ft_print_pointer(print);
	if (print->flag_type_percent)
		*length += ft_print_percent(print);
}

void	ft_init_spec(t_printf *s_printf)
{
	s_printf->flag_minus = 0;
	s_printf->flag_zero = 0;
	s_printf->flag_shirina_len = -1;
	s_printf->flag_tochnost = 0;
	s_printf->flag_tochnost_len = -1;
	s_printf->flag_type_di = 0;
	s_printf->flag_type_znach = 0;
	s_printf->flag_type_c = 0;
	s_printf->flag_c_znach = 0;
	s_printf->flag_type_s = 0;
	s_printf->flag_c_znach = 0;
	s_printf->flag_type_u = 0;
	s_printf->flag_type_x_l = 0;
	s_printf->flag_type_x_b = 0;
	s_printf->flag_base = 0;
	s_printf->flag_type_p = 0;
	s_printf->flag_type_percent = 0;
}

int	ft_printf(const char *str, ...)
{
	int			length;
	va_list		factor;
	t_printf	print;

	length = 0;
	va_start(factor, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_put_char(*str);
			str++;
			length++;
		}
		if (*str == '%')
		{
			ft_init_spec(&print);
			str = ft_specificator(str, &print, factor);
			ft_type_print(&print, &length);
			str++;
		}
	}
	va_end(factor);
	return (length);
}

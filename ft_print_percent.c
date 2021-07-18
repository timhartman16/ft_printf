#include "ft_printf.h"

int	ft_if_minus(t_printf *s_printf, int kol_symb)
{
	int	length;

	length = 0;
	if (s_printf->flag_minus == 0)
	{
		if (s_printf->flag_zero == 1)
			length += 1 + ft_symbols(kol_symb, '0');
		else
			length += 1 + ft_symbols(kol_symb, ' ');
		ft_put_char('%');
	}
	else
	{
		ft_put_char('%');
		length += 1 + ft_symbols(kol_symb, ' ');
	}
	return (length);
}

int	ft_print_percent(t_printf *s_printf)
{
	int	length;
	int	kol_symb;

	length = 0;
	kol_symb = 0;
	if (s_printf->flag_shirina_len == -1 || s_printf->flag_shirina_len == 1)
	{
		ft_put_char('%');
		length++;
	}
	else
	{
		kol_symb = s_printf->flag_shirina_len - 1;
		length += ft_if_minus(s_printf, kol_symb);
	}
	return (length);
}

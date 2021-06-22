#include "ft_printf.h"

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

int	ft_minus_or_not(t_printf *s_printf, int kol_probely)
{
	int	length;

	length = 0;
	if (s_printf->flag_minus == 1)
	{
		ft_put_char(s_printf->flag_c_znach);
		length += ft_symbols(kol_probely, ' ') + 1;
	}
	else
	{
		length += ft_symbols(kol_probely, ' ') + 1;
		ft_put_char(s_printf->flag_c_znach);
	}
	return (length);
}

int	ft_print_char(t_printf *s_printf)
{
	int	length;
	int	kol_probely;

	length = 0;
	kol_probely = 0;
	if (s_printf->flag_shirina_len > 1)
		kol_probely = s_printf->flag_shirina_len - 1;
	if (s_printf->flag_shirina_len == 1 || s_printf->flag_shirina_len == -1)
	{
		ft_put_char(s_printf->flag_c_znach);
		length++;
	}
	else
		length += ft_minus_or_not(s_printf, kol_probely);
	return (length);
}

#include "ft_printf.h"

int	ft_iff_minus(t_printf *s_printf, int kol_probely)
{
	int	length;

	length = 0;
	if (s_printf->flag_minus == 1)
	{
		write(1, "0x", 2);
		length += ft_put_int(s_printf->flag_type_znach,
				s_printf->flag_base, s_printf->flag_type_x_l);
		length += ft_symbols(kol_probely, ' ');
	}
	else
	{
		length += ft_symbols(kol_probely, ' ');
		write(1, "0x", 2);
		length += ft_put_int(s_printf->flag_type_znach,
				s_printf->flag_base, s_printf->flag_type_x_l);
	}
	return (length);
}

int	ft_print_pointer(t_printf *s_printf)
{
	int	length;
	int	len_chisla;
	int	kol_probely;

	length = 0;
	kol_probely = 0;
	len_chisla = 2 + ft_num_len(s_printf->flag_type_znach, s_printf->flag_base);
	if (len_chisla >= s_printf->flag_shirina_len)
	{
		write(1, "0x", 2);
		length += ft_put_int(s_printf->flag_type_znach,
				s_printf->flag_base, s_printf->flag_type_x_l);
	}
	else
	{
		kol_probely = s_printf->flag_shirina_len - len_chisla;
		length += ft_iff_minus(s_printf, kol_probely);
	}
	return (length + len_chisla);
}

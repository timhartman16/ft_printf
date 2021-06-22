#include "ft_printf.h"

int	ft_31uslovie(int len_chisla, t_printf *s_printf, int flag_znak)
{
	int	kol_probely;
	int	length;

	kol_probely = 0;
	length = 0;
	kol_probely = s_printf->flag_shirina_len - flag_znak - len_chisla;
	length += ft_symbols(kol_probely, ' ');
	length += ft_print_znak(flag_znak);
	if (s_printf->flag_tochnost == 1)
	{
		ft_put_char(' ');
		length++;
	}
	else
		length += len_chisla + ft_put_int(s_printf->flag_type_znach,
				s_printf->flag_base, s_printf->flag_type_x_l);
	return (length);
}

int	ft_32uslovie(int len_chisla, t_printf *s_printf, int flag_znak)
{
	int	kol_probely;
	int	length;

	kol_probely = 0;
	length = 0;
	kol_probely = s_printf->flag_shirina_len - flag_znak - len_chisla;
	length += ft_print_znak(flag_znak);
	length += ft_symbols(kol_probely, '0');
	length += len_chisla + ft_put_int(s_printf->flag_type_znach,
			s_printf->flag_base, s_printf->flag_type_x_l);
	return (length);
}

int	ft_33uslovie(int len_chisla, t_printf *s_printf, int flag_znak)
{
	int	kol_probely;
	int	length;

	kol_probely = 0;
	length = 0;
	kol_probely = s_printf->flag_shirina_len - flag_znak - len_chisla;
	length += ft_print_znak(flag_znak);
	if (s_printf->flag_tochnost == 1)
	{
		ft_put_char(' ');
		length++;
	}
	else
		length += len_chisla + ft_put_int(s_printf->flag_type_znach,
				s_printf->flag_base, s_printf->flag_type_x_l);
	length += ft_symbols(kol_probely, ' ');
	return (length);
}

int	ft_3uslovie(int len_chisla, t_printf *s_printf, int flag_znak)
{
	int	length;

	length = 0;
	if (s_printf->flag_zero == 0 && s_printf->flag_minus == 0)
		return (ft_31uslovie(len_chisla, s_printf, flag_znak));
	if (s_printf->flag_zero == 1 && s_printf->flag_minus == 0)
		return (ft_32uslovie(len_chisla, s_printf, flag_znak));
	if (s_printf->flag_zero == 0 && s_printf->flag_minus == 1)
		return (ft_33uslovie(len_chisla, s_printf, flag_znak));
	return (length);
}

#include "ft_printf.h"

int	ft_2uslovie(int len_chisla, t_printf *s_printf, int flag_znak)
{
	int	length;

	length = 0;
	if (s_printf->flag_tochnost == 1 && s_printf->flag_tochnost_len <= 0
		&& s_printf->flag_type_znach == 0)
	{
		ft_put_char(' ');
		length++;
	}
	else
	{
		length += ft_print_znak(flag_znak);
		length += len_chisla + ft_put_int(s_printf->flag_type_znach,
				s_printf->flag_base, s_printf->flag_type_x_l);
	}
	return (length);
}

int	ft_4uslovie(int len_chisla, t_printf *s_printf, int flag_znak)
{
	int	kol_null;
	int	length;

	kol_null = 0;
	length = 0;
	kol_null = s_printf->flag_tochnost_len - len_chisla;
	length += ft_print_znak(flag_znak);
	length += ft_symbols(kol_null, '0');
	length += len_chisla + ft_put_int(s_printf->flag_type_znach,
			s_printf->flag_base, s_printf->flag_type_x_l);
	return (length);
}

int	ft_5uslovie(int len_chisla, t_printf *s_printf, int flag_znak, int kol_null)
{
	int	length;
	int	kol_probely;

	length = 0;
	if (s_printf->flag_tochnost_len >= len_chisla)
	{
		kol_null = s_printf->flag_tochnost_len - len_chisla;
		kol_probely = s_printf->flag_shirina_len
			- flag_znak - s_printf->flag_tochnost_len;
	}
	else
		kol_probely = s_printf->flag_shirina_len - flag_znak - len_chisla;
	if (s_printf->flag_tochnost_len == 0 && s_printf->flag_type_znach == 0)
	{
		length += ft_symbols(s_printf->flag_shirina_len, ' ');
		return (length);
	}
	if (s_printf->flag_minus == 0)
		length += ft_symbols(kol_probely, ' ');
	length += ft_print_znak(flag_znak) + ft_symbols(kol_null, '0');
	length += len_chisla + ft_put_int(s_printf->flag_type_znach,
			s_printf->flag_base, s_printf->flag_type_x_l);
	if (s_printf->flag_minus == 1)
		length += ft_symbols(kol_probely, ' ');
	return (length);
}

int	ft_check_di(int len_chisla, t_printf *s_printf, int flag_znak, int kol_null)
{
	int	length;

	length = 0;
	if (s_printf->flag_shirina_len <= 0 && s_printf->flag_tochnost_len <= 0
		&& s_printf->flag_type_znach == 0 && s_printf->flag_tochnost == 1)
		return (length);
	if (len_chisla >= s_printf->flag_shirina_len
		&& len_chisla >= s_printf->flag_tochnost_len)
		return (ft_2uslovie(len_chisla, s_printf, flag_znak));
	if (s_printf->flag_shirina_len > 0 && s_printf->flag_tochnost_len == -1)
		return (ft_3uslovie(len_chisla, s_printf, flag_znak));
	if ((s_printf->flag_shirina_len == -1 && s_printf->flag_tochnost_len >= 0)
		|| (s_printf->flag_tochnost_len >= s_printf->flag_shirina_len))
		return (ft_4uslovie(len_chisla, s_printf, flag_znak));
	if (s_printf->flag_tochnost_len < s_printf->flag_shirina_len)
		return (ft_5uslovie(len_chisla, s_printf, flag_znak, kol_null));
	return (length);
}

int	ft_print_int(t_printf *s_printf)
{
	int	len_chisla;
	int	kol_null;
	int	flag_znak;
	int	length;

	kol_null = 0;
	flag_znak = 0;
	length = 0;
	if (s_printf->flag_type_znach < 0)
	{
		flag_znak = 1;
		s_printf->flag_type_znach = -s_printf->flag_type_znach;
	}
	len_chisla = ft_num_len(s_printf->flag_type_znach, s_printf->flag_base);
	return (ft_check_di(len_chisla, s_printf, flag_znak, kol_null));
}

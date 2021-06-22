#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_put_str(char *s, int str_len)
{
	int	i;

	i = 0;
	if (!(s))
		return ;
	while (s && s[i] != '\0' && str_len)
	{
		ft_put_char(s[i]);
		i++;
		str_len--;
	}
}

int	ft_check_usloviya(t_printf *s_printf, int str_len, int kol_probely)
{
	int	length;

	length = 0;
	if (s_printf->flag_tochnost_len >= 1
		&& s_printf->flag_tochnost_len < str_len)
		str_len = s_printf->flag_tochnost_len;
	if (str_len < s_printf->flag_shirina_len)
		kol_probely = s_printf->flag_shirina_len - str_len;
	else
	{
		ft_put_str(s_printf->flag_s_znach, str_len);
		return (length + str_len);
	}
	if (s_printf->flag_minus == 0)
	{
		length += ft_symbols(kol_probely, ' ');
		ft_put_str(s_printf->flag_s_znach, str_len);
	}
	else
	{
		ft_put_str(s_printf->flag_s_znach, str_len);
		length += ft_symbols(kol_probely, ' ');
	}
	return (length + str_len);
}

int	ft_print_string(t_printf *s_printf)
{
	int	length;
	int	str_len;
	int	kol_probely;

	length = 0;
	kol_probely = 0;
	if (s_printf->flag_s_znach == NULL)
		s_printf->flag_s_znach = "(null)";
	str_len = ft_strlen(s_printf->flag_s_znach);
	if (s_printf->flag_tochnost == 1 && s_printf->flag_tochnost_len <= 0
		&& s_printf->flag_shirina_len <= 0)
		return (length);
	if (s_printf->flag_tochnost == 1 && s_printf->flag_tochnost_len <= 0
		&& s_printf->flag_shirina_len > 0)
	{
		length += ft_symbols(s_printf->flag_shirina_len, ' ');
		return (length);
	}
	else
		length += ft_check_usloviya(s_printf, str_len, kol_probely);
	return (length);
}

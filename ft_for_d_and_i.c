#include "ft_printf.h"

int	ft_num_len(long long int num, int base)
{
	int	len;

	len = 1;
	while (num > base - 1)
	{
		num /= base;
		len++;
	}
	return (len);
}

int	ft_symbols(int kol, char symbol)
{
	int	length;

	length = 0;
	while (kol)
	{
		ft_put_char(symbol);
		kol--;
		length++;
	}
	return (length);
}

int	ft_print_znak(int flag_znak)
{
	int	length;

	length = 0;
	if (flag_znak == 1)
	{
		ft_put_char('-');
		length++;
	}
	else
		return (length);
	return (length);
}

int	ft_put_int(long long int n, int base, int flag)
{
	if (n > base - 1)
	{
		ft_put_int(n / base, base, flag);
		ft_put_int(n % base, base, flag);
	}
	else
	{	
		if (base == 10)
			ft_put_char(n + '0');
		else if (base == 16 && flag == 0)
		{
			if (n >= 0 && n <= 9)
				ft_put_char(n + '0');
			if (n >= 10 && n <= 15)
				ft_put_char(n + 55);
		}
		else if (base == 16 && flag == 1)
		{
			if (n >= 0 && n <= 9)
				ft_put_char(n + '0');
			if (n >= 10 && n <= 15)
				ft_put_char(n + 87);
		}
	}
	return (0);
}

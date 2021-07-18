#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
	int					flag_minus;
	int					flag_zero;
	int					flag_shirina_len;
	int					flag_tochnost;
	int					flag_tochnost_len;
	int					flag_type_di;
	int					flag_type_c;
	int					flag_type_s;
	int					flag_type_u;
	int					flag_type_x_l;
	int					flag_type_x_b;
	int					flag_type_p;
	int					flag_type_percent;
	long long int		flag_type_znach;
	char				flag_c_znach;
	char				*flag_s_znach;
	int					flag_base;
}	t_printf;

int		ft_atoi(const char *str);
int		ft_num_len(long long int num, int base);
int		ft_print_int(t_printf *s_printf);
int		ft_put_int(long long int n, int base, int flag);
void	ft_put_char(char c);
int		ft_symbols(int kol, char symbol);
int		ft_print_znak(int flag_znak);
int		ft_3uslovie(int len_chisla, t_printf *s_printf, int flag_znak);
int		ft_print_char(t_printf *s_printf);
int		ft_print_string(t_printf *s_printf);
int		ft_print_pointer(t_printf *s_printf);
int		ft_print_percent(t_printf *s_printf);
char	*ft_specificator(const char *str, t_printf *s_printf, va_list factor);

#endif
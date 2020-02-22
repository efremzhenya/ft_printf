#include "ft_printf.h"

char 				*ft_ftoa(char *mnt, int e, t_format *format)
{
	char 			*res;
	int				i;

}

char 				*put_bits(unsigned char *mnt)
{
	char 			*res_mnt;
	int				i;
	int				n;
	int				bit_mask;

	res_mnt = ft_strnew(64);
	i = 0;
	n = 0;
	while (n < 8)
	{
		bit_mask = 1;
		while (bit_mask != 256)
		{
			res_mnt[i] = (mnt[n] & bit_mask) ? 1 : 0;
			bit_mask <<= 1;
			i++;
		}
		n++;
	}
	return (res_mnt);
}

char				*get_value(t_format *params, int e, unsigned long m)
{
	char			*str_mant;
	char			*out;

	if (e <= -16383 ||  e >= 16384)
		out = exceptions(m, params->sign);
	else
	{
		str_mant = put_bits((unsigned char *)&m);
		out = ft_ftoa(str_mant, e, params);
	}
	return (out);
}

size_t 				print_float(t_format *param, va_list ap)
{
	int 			e;
	unsigned long	m;
	char 			*res;

	if (param->left && param->right)
		fill_float_params(param);
	if (ap == NULL)
		return (0);
	if (param->size == 5)
		fl.num = va_arg(ap, long double);
	else
		fl.num = (long double)va_arg(ap, double);
	param->sign = fl.val.sign;
	if (fl.val.exp != 1)
	{
		e = fl.val.exp - 16363;
		m = fl.val.mant;
	}
	else
	{
		e = 1;
		m = 0;
	}
	res = get_value(param, e , m);
	return (str_to_out(res));
}
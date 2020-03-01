#include "ft_printf.h"


t_format 			*ftoa_exp(int expoftwo, char *res, t_format *format)
{
	int				i;

	i = 0;
	while (ft_abs(expoftwo) > i++)
		res = ft_add(res, res, 0, 1);
	if (expoftwo < 0)
	{
		res = ft_negs(res);
		format->adot = ft_add(res, format->adot, 1, 2);
	}
	else
		format->bdot = ft_add(res, format->bdot, 0, 2);
	return (format);
}

char 				*ft_ftoa(char *mnt, int e, t_format *format)
{
	char 			*res;
	int				i;
	int 			shift;
	int 			val;
	int 			expoftwo;

	i = 63;
	shift = 0;
	while (i >= 0)
	{
		val = mnt[i];
		if (val == 1)
		{
			res  = ft_strdup("1");
			expoftwo = e - shift;
			format = ftoa_exp(expoftwo, res, format);
		}
	}

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

	if (param->bdot && param->adot)
		clear_float_params(param);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:35:21 by lseema            #+#    #+#             */
/*   Updated: 2020/02/14 16:10:15 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		print_unsigned(t_format *param, va_list ap)
{
	unsigned long long	arg;
	char				*tmp;
	char				*str;
	size_t				len;

	if (param->size == 4)
		arg = va_arg(ap, unsigned long long);
	else if (param->size == 3)
		arg = (unsigned long)va_arg(ap, unsigned long long);
	else if (param->size == 2)
		arg = (unsigned short)va_arg(ap, unsigned long long);
	else if (param->size == 1)
		arg = (unsigned char)va_arg(ap, unsigned long long);
	else
		arg = va_arg(ap, unsigned int);
	tmp = (!arg && param->precision) ? ft_strdup("") : ft_itoa_base(arg, 10, 0);
	str = fill_zero_unsigned(param, tmp, ft_strlen(tmp));
	str = print_width(param, str, ft_strlen(str));
	len = write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return len;
}

char	*fill_zero_unsigned(t_format *params, char *str, size_t len)
{
	char	*tmp;
	char	*new;
	int		i;

	i = 0;
	if (params->precision > (int)len)
	{
		tmp = ft_strnew(params->precision - len + 1);
		while (i < params->precision - (int)len)
			tmp[i++] = '0';
		new = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

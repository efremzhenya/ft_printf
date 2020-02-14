/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbolic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:55:26 by lseema            #+#    #+#             */
/*   Updated: 2020/02/14 19:31:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		print_percent(t_format *param)
{
	char	*tmp;
	char	*new;
	int		i;

	i = 0;
	if (param->width > 1)
	{
		tmp = ft_strnew(param->width - 1);
		while (i < (int)(param->width - 1))
			tmp[i++] = (param->minus_zero != '0') ? ' ' : '0';
		new = (param->minus_zero == '-')
			? ft_strjoin("%", tmp) : ft_strjoin(tmp, "%");
		ft_strdel(&tmp);
		i = write(1, new, ft_strlen(new));
		ft_strdel(&new);
		return (i);
	}
	return (write(1, "%", 1));
}

size_t		print_chr(t_format *param, va_list ap)
{
	char	arg;
	size_t	len;
	size_t	count;

	arg = ('c' == param->type) ? (char)va_arg(ap, int) : param->type;
	if (param->width > 1)
	{
		count = ('-' == param->minus_zero) ? write(1, &arg, 1) : 0;
		len = param->width - 1;
		while (len > 0)
		{
			count += write(1, (param->minus_zero != '0') ? " " : "0", 1);
			len--;
		}
		if (param->minus_zero != '-')
			count += write(1, &arg, 1);
	}
	else
		count = write(1, &arg, 1);
	return (count);
}

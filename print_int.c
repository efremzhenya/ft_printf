/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:17:54 by lseema            #+#    #+#             */
/*   Updated: 2020/02/14 15:31:27 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	5 - L
	4 - ll
	3 - l
	2 - h
	1 - hh
*/
size_t		print_int(t_format *param, va_list ap)
{
	long long int	arg;
	char			*tmp;
	char			*str;
	ssize_t			sign;
	//Приведение в тип в соответсвии с размерностью
	if (param->size == 4)
		arg = va_arg(ap, long long int);
	else if (param->size == 3)
		arg = (long int)va_arg(ap, long int);
	else if (param->size == 2)
		arg = (short)va_arg(ap, long long int);
	else if (param->size == 1)
		arg = (signed char)va_arg(ap, long long int);
	else
		arg = (int)va_arg(ap, long long int);
	sign = (arg < 0) ? -1 : 1;
	//Первеод в строку
	tmp = (param->precision == 0 && arg == 0)
		? ft_strdup("") : ft_itoa_base(arg * sign, 10, 0);
	str = print_int2(param, tmp, sign);
	sign = write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (sign);
}

char	*print_int2(t_format *param, char *str, int sign)
{
	char	*new;
	//Добавление минуса в строку
	if (sign == -1)
	{
		new = str;
		str = ft_strjoin("-", str);
		ft_strdel(&new);
	}
	//Если точность больше длины строки, то преобразовываем с соответствии с точностью
	new = param->precision >= (int)ft_strlen(str)
		? fill_zero(param, str, ft_strlen(str)) : str;
	if (!ft_strchr(new, '-') && param->plus_space)
	{
		str = ('+' == param->plus_space)
			? ft_strjoin("+", new) : ft_strjoin(" ", new);
		ft_strdel(&new);
	}
	new = print_width(param, new, ft_strlen(new));
	return (new);
}

char		*fill_zero(t_format *param, char *str, size_t len)
{
	int		diff;
	char	*tmp;
	char	*new;

	/* Заполняем нулями до величины точности */
	diff = (str[0] == '-')
		? param->precision - (int)len + 1 : param->precision - (int)len;
	tmp = ft_strnew(diff);
	while (diff > 0)
		tmp[diff-- - 1] = '0';
	//Если преобразование в шестнадцатеричную...
	new = ((param->type == 'x' || param->type == 'X') &&
		(str[1] == 'x' || str[1] == 'X'))
		? split_and_assemble(param, str, tmp)
		: add_atributes_precision(tmp, str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (new);
}

char	*print_width(t_format *params, char *str, size_t len)
{
	char *tmp;
	char *new;

	if (params->width > len)
	{
		len = params->width - len;
		tmp = ft_strnew(len);
		tmp = ft_memset(tmp, ((params->minus_zero == '0' &&
			params->precision == -1) ? '0' : ' '), len);
		if ('0' == params->minus_zero && params->type != 'u')
			new = add_atributes_width(params, str, tmp);
		else if ('0' == params->minus_zero && 'p' == params->type)
			new = split_and_assemble(params, str, tmp);
		else if ('-' == params->minus_zero)
			new = ft_strjoin(str, tmp);
		else
			new = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

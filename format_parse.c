/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:51:14 by lseema            #+#    #+#             */
/*   Updated: 2020/02/15 17:52:38 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Читаем формат %[флаги][ширина][.точность][размер]тип
*/
void	format_parser(const char *format, t_format *param, va_list ap)
{
	flags_parser(format, param);
	width_prcsn_parser(format, param, ap);
	size_parser(format, param);
	param->type = format[param->i];
}

/*
	Читаем флаги # + - 0 space
*/
void	flags_parser(const char *format, t_format *param)
{
	size_t i;

	i = param->i;
	while (format[i] == '#' || format[i] == '0' || format[i] == ' ' ||
			format[i] == '+' || format[i] == '-')
	{
		if (format[i] == '#')
			param->hash = '#';
		else if ((format[i] == '-' || format[i] == '0')
				&& param->minus_zero != '-')
				param->minus_zero = format[i];
		else if ((format[i] == '+' || format[i] == ' ')
				&& (param->plus_space != '+'))
				param->plus_space = format[i];
		i = ++param->i;
	}
}

/*
	Читаем ширину и точность
*/
void	width_prcsn_parser(const char *format, t_format *param, va_list ap)
{
	//Ширина
	if (format[param->i] >= '0' && format[param->i] <= '9')
	{
		param->width = ft_atoi(format + param->i);
		while (format[param->i]>= '0' && format[param->i] <= '9')
			param->i++;
	}
	else if (format[param->i] == '*' && ++param->i)
		param->width = va_arg(ap, int);
	//Точность
	if (format[param->i] == '.' && format[++param->i] != '*')
	{
		param->precision = ft_atoi(format + param->i);
		while (format[param->i]>= '0' && format[param->i] <= '9')
			param->i++;
	}
	else if (format[param->i] == '*' && ++param->i)
		param->precision = va_arg(ap, int);
}

/*
	Читаем размер. h - short, l - long
*/
void	size_parser(const char *format, t_format *param)
{
	size_t h;
	size_t l;
	size_t big_l;

	big_l = 0;
	l = 0;
	h = 0;
	while (format[param->i] == 'h' || format[param->i] == 'l' ||
		format[param->i] =='L')
	{
		format[param->i] == 'h' ? h++ : format[param->i] == 'l' ? l++ : big_l++;
		param->i++;
	}
	if (big_l)
		param->size = 5;
	else if (big_l == 2  || (l > 0 && l % 2 == 0))
		param->size = 4;
	else if (l > 0)
		param->size = 3;
	else if (h % 2 != 0 && h > 0)
		param->size = 2;
	else if (h > 0)
		param->size = 1;
}

/*
	В соответcвии со спецификатором вызывает функцию печати аргумента для конкретного типа
*/
size_t		print_argument(t_format *param, char c, va_list ap)
{
	if (c == 'd' || c == 'i')
	 	return (print_int(param, ap));
	else if (c == 'o')
		return (print_oct(param, ap));
	else if (c == 'u')
	 	return (print_unsigned(param, ap));
	else if (c == 'x' || c == 'X')
	 	return (print_hex(param, ap));
	else if (c == 's')
		return (print_str(param, ap));
	else if (c == 'p')
		return (print_pointer(param, ap));
	// else if (c == 'f' || c == 'e' || c == 'g')
	// 	return (print_float(param, ap));
	else if (c == '%')
		return (print_percent(param));
	else
		return (print_chr(param, ap));
	return (0);
}

// size_t		print_float(t_format *param, va_list ap)
// {
// 	return;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:36:11 by lseema            #+#    #+#             */
/*   Updated: 2020/02/17 18:40:35 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Возвращает количество выведенных символов,
**	либо -1 при пустом входном формате.
**	Принимает формат и переменное количество аргументов.
*/

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	if (!format)
		return (-1);
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
		return (0);
	i = format_manager(format, ap);
	va_end(ap);
	return (i);
}

/*
**	Обработчик формата.
**	Вызывается парсер формата, пока не закончилась строка формата.
**	После чтения очередного спецификатора вызывается очистка параметров формата.
**	Возвращает количество выведенных символов.
*/

size_t		format_manager(const char *format, va_list ap)
{
	size_t		length;
	t_format	*param;

	length = 0;
	param = format_initialize();
	while (format[param->i])
	{
		if (format[param->i] == '{' && format[param->i + 1 != '%'])
		 	param->i += colorize(&format[param->i + 1]);
		if (format[param->i] == '%')
		{
			param->i++;
			format_parser(format, param, ap);
			length += print_argument(param, param->type, ap);
			format_clean(param);
			if (format[param->i++] == '\0')
				break ;
		}
		else
			length += write(1, &format[param->i++], 1);
	}
	free(param);
	return (length);
}

/*
**	Задаются начальные значения формата
*/

t_format	*format_initialize(void)
{
	t_format	*param;

	if (!(param = (t_format*)malloc(sizeof(t_format))))
		return (NULL);
	param->hash = '\0';
	param->minus_zero = '\0';
	param->plus_space = '\0';
	param->precision = -1;
	param->i = 0;
	param->width = 0;
	return (param);
}

/*
**	Обнуление к начальному состоянию для чтения
**	следующего неизвестного параметра
*/

void		format_clean(t_format *param)
{
	param->hash = '\0';
	param->minus_zero = '\0';
	param->plus_space = '\0';
	param->precision = -1;
	param->width = 0;
	param->size = 0;
	param->type = '\0';
	param->float_type = '\0';
}

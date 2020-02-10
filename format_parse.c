/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:51:14 by lseema            #+#    #+#             */
/*   Updated: 2020/02/10 19:14:10 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Читаем формат */
void	format_parser(const char *format, t_format *params, va_list ap)
{
	flags_parser(format, params);
}

/* Читаем флаги */
void	flags_parser(const char *format, t_format *params)
{
	size_t i;

	i = params->i;
	while (format[i] == '#' || format[i] == '0' || format[i] == ' ' ||
			format[i] == '+' || format[i] == '-')
	{
		if (format[i] == '#')
			params->hash = '#';
		else if ((format[i] == '-' || format[i] == '0')
				&& params->minus_zero != '-')
				params->minus_zero = format[i];
		else if ((format[i] == '+' || format[i] == ' ')
				&& (params->plus_space != '+'))
		i = ++params->i;
	}
}

/* Читаем ширину и точность*/
void	width_prcsn_parser(const char *format, t_format *params, va_list ap)
{
	if (format[params->i] >= '0' && format[params->i] <= '9')
	{
		params->width = ft_atoi(format + params->i);
		while (format[params->i]>= '0' && format[params->i] <= '9');
			params->i++;
	}

}

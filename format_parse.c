/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:51:14 by lseema            #+#    #+#             */
/*   Updated: 2020/02/10 16:23:59 by lseema           ###   ########.fr       */
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

}

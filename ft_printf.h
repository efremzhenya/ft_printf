/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:10 by lseema            #+#    #+#             */
/*   Updated: 2020/02/11 20:51:17 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_format
{
    //Индекс обрабатываемого символа формата
    ssize_t i;
    //Флаг хэша
    char    hash;
    //Флаг -, 0
    char    minus_zero;
    //Флаг + или space
    char    plus_space;
    //Ширина
    ssize_t width;
    //Точность
    ssize_t precision;
    //Размер
    int     size;
}               t_format;

int         ft_printf(const char *format, ...);
ssize_t     format_manager(const char *format, va_list ap);
void        format_clean(t_format *param);
t_format    *format_initialize(void);
void        format_parser(const char *format, t_format *param, va_list ap);
void        flags_parser(const char *format, t_format *param);
void        width_prcsn_parser(const char *format, t_format *param, va_list ap);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:10 by lseema            #+#    #+#             */
/*   Updated: 2020/02/10 16:48:18 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_format
{
    //Флаг хэша
    char    hash;
    //Флаг -, 0
    char    minus_zero;
    //Точность
    int     accuracy;
    //Флаг +, -
    char    plus_zero;
    //Текущий обрабатываемый символ формата
    ssize_t count_f;
}               t_format;

int         ft_printf(const char *format, ...);
ssize_t     format_manager(const char *format, va_list ap);
void        format_clean(t_format *params);
void        format_parser(const char *format, t_format *params, va_list ap);
void        flags_parser(const char *format, t_format *params);
t_format    *format_init(void);

#endif

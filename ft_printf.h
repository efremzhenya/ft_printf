/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:10 by lseema            #+#    #+#             */
/*   Updated: 2020/02/12 19:15:31 by lseema           ###   ########.fr       */
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
    char    type;
    char    float_type;
}               t_format;

int         ft_printf(const char *format, ...);
size_t      format_manager(const char *format, va_list ap);
void        format_clean(t_format *param);
t_format    *format_initialize(void);
void        format_parser(const char *format, t_format *param, va_list ap);
void        flags_parser(const char *format, t_format *param);
void        width_prcsn_parser(const char *format, t_format *param, va_list ap);
void        size_parser(const char *format, t_format *param);
size_t		print_argument(t_format *param, char s, va_list ap);
size_t		print_int(t_format *param, va_list ap);
size_t		print_oct(t_format *param, va_list ap);
size_t		print_unsigned(t_format *param, va_list ap);
size_t		print_hex(t_format *param, va_list ap);
size_t		print_str(t_format *param, va_list ap);
size_t		print_pointer(t_format *param, va_list ap);
size_t		print_percent(t_format *param);
size_t		print_chr(t_format *param, va_list ap);
size_t		print_float(t_format *param, va_list ap);
#endif

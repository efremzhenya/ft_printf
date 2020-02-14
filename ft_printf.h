/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:10 by lseema            #+#    #+#             */
/*   Updated: 2020/02/14 16:10:43 by lseema           ###   ########.fr       */
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
    size_t i;
    //Флаг хэша
    char    hash;
    //Флаг -, 0
    char    minus_zero;
    //Флаг + или space
    char    plus_space;
    //Ширина
    size_t width;
    //Точность
    int precision;
    //Размер
    int     size;
    char    type;
    char    float_type;
}               t_format;

int         ft_printf(const char *format, ...);
size_t      format_manager(const char *format, va_list ap);
void        format_clean(t_format *param);
t_format    *format_initialize(void);
void		format_parser(const char *format, t_format *param, va_list ap);
void		flags_parser(const char *format, t_format *param);
void        width_prcsn_parser(const char *format, t_format *param, va_list ap);
void        size_parser(const char *format, t_format *param);
size_t		print_argument(t_format *param, char s, va_list ap);
size_t		print_int(t_format *param, va_list ap);
// size_t		print_oct(t_format *param, va_list ap);
size_t		print_unsigned(t_format *param, va_list ap);
// size_t		print_hex(t_format *param, va_list ap);
// size_t		print_str(t_format *param, va_list ap);
// size_t		print_pointer(t_format *param, va_list ap);
// size_t		print_percent(t_format *param);
// size_t		print_chr(t_format *param, va_list ap);
// size_t		print_float(t_format *param, va_list ap);
char		*ft_itoa_base(unsigned long long value, int base, int reg);
char		*print_int2(t_format *param, char *str, int sign);
char		*fill_zero(t_format *param, char *str, size_t len);
char	    *fill_zero_unsigned(t_format *params, char *str, size_t len);
char		*print_width(t_format *params, char *str, size_t len);
char		*add_atributes_width(t_format *params, char *str, char *tmp);
char		*split_and_assemble(t_format *params, char *str, char *tmp);
char		*add_atributes_precision(char *tmp, char *str);
#endif

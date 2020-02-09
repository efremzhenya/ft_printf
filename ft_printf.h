/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:10 by lseema            #+#    #+#             */
/*   Updated: 2020/02/09 21:16:54 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_format
{
    char    hash;
    char    minus_zero;
    int     accurence;
    char    plus_zero;
}               t_format;

int         ft_printf(const char *format, ...);
ssize_t     print_format(const char *format, va_list ap);


#endif
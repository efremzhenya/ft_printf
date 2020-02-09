/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:00 by lseema            #+#    #+#             */
/*   Updated: 2020/02/09 21:45:53 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list ap;
    size_t  i;

    i = 0;
    if (!format)
        return(-1);
    va_start(ap, format);
    if (format[0] == '%' && format[1] == '\0')
        return (i);
    i = print_format(format, ap);
    return (i);
}

ssize_t     print_format(const char *format, va_list ap)
{
    ssize_t     i;
    t_format    *params;

    i = 0;
    params = init_format();
    return (0);
}

t_format    *init_format(void)
{
    t_format    *params;

    if (!(params = (t_format*)malloc(sizeof(t_format))))
        return (NULL);
    params->hash = '\0';
    params->minus_zero = '\0';
    params->plus_zero = '\0';
    params->accurence = -1;

}

int         main(void)
{
    ft_printf("","");
    return (0);
}

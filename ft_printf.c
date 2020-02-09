/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:00 by lseema            #+#    #+#             */
/*   Updated: 2020/02/09 20:18:27 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list ap;
    size_t  i;

    if (!format)
        return(-1);
    va_start(ap, format);
    i = 0;
    return (i);
}

int     main(void)
{
    ft_printf("","");
    return (0);
}

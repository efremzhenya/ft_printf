/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:09:00 by lseema            #+#    #+#             */
/*   Updated: 2020/02/10 18:55:04 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
    Главная функция, возвращает количество выведенных символов,
    либо -1 при пустом входном формате.
    Принимает формат и переменное количество аргументов.
 */

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
    i = format_manager(format, ap);
    va_end(ap);
    return (i);
}

/*
    Обработчик формата. Вызывает парсер формата, пока не закончилась строка формата.
    После чтения очередного спецификатора вызывается оичстка параметров формата.
    Возвращает количество выведенных символов.
*/

ssize_t     format_manager(const char *format, va_list ap)
{
    ssize_t     i;
    t_format    *params;

    i = 0;
    params = format_init();
    while (format[params->i])
    {
        params->i++;
        format_parser(format, params, ap);
        format_clean(params);
        if (format[params->i] == '\0')
            break;
        params->i++;
    }
    free(params);
    return (i);
}

/*
    Задаются начальные значения неизвестного параметра формата
*/
t_format    *format_initialize(void)
{
    t_format    *params;

    if (!(params = (t_format*)malloc(sizeof(t_format))))
        return (NULL);
    params->hash = '\0';
    params->minus_zero = '\0';
    params->plus_space = '\0';
    params->precision = -1;
    params->i = 0;
    params->width = 0;
    return (params);
}

/*
    Обнуление к начальному состоянию структуры формата для чтения
    следующего неизвестного параметра
*/
void    format_clean(t_format *params)
{
    params->hash = '\0';
    params->minus_zero = '\0';
    params->plus_space = '\0';
    params->precision = -1;
    params->i = 0;
    params->width = 0;
}

int         main(void)
{
    ft_printf("","");
    return (0);
}

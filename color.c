/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:44:41 by lseema            #+#    #+#             */
/*   Updated: 2020/02/17 18:55:42 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		colorize(const char *s)
{
	short int	i;
	char		color[8];

	i = 0;
	while (*s != '}' && *s != '\0' && i <= 6)
		*(color + i++) = ft_toupper(*s++);
	color[i] = '\0';
	return (*s == '}' && put_color(color)) ? (i + 2) : (0);
}

int		put_color(char *color)
{
	if (!ft_strcmp(color, "EOC"))
		ft_putstr(RESET);
	else if (!ft_strcmp(color, "RED"))
		ft_putstr(RED);
	else if (!ft_strcmp(color, "GREEN"))
		ft_putstr(GREEN);
	else if (!ft_strcmp(color, "YELLOW"))
		ft_putstr(YELLOW);
	else if (!ft_strcmp(color, "BLUE"))
		ft_putstr(BLUE);
	else if (!ft_strcmp(color, "WHITE"))
		ft_putstr(WHITE);
	else if (!ft_strcmp(color, "BLACK"))
		ft_putstr(BLACK);
	else if (!ft_strcmp(color, "CYAN"))
		ft_putstr(CYAN);
	else if (!ft_strcmp(color, "MAGENTA"))
		ft_putstr(MAGENTA);
	else
		return (0);
	return (1);
}

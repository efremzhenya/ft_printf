/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:08:34 by kysgramo          #+#    #+#             */
/*   Updated: 2020/03/03 21:45:19 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 		ft_abs(int	nb)
{
	return (nb > 0 ? nb : -nb);
}

size_t 		ft_max(char *s1, char *s2)
{
	size_t 	l1;
	size_t	l2;

	return ((l1 = ft_strlen(s1)) > (l2 = ft_strlen(s2)) ? l1 : l2);
}

size_t 		ft_min(char *s1, char *s2)
{
	size_t 	l1;
	size_t	l2;

	return ((l1 = ft_strlen(s1)) < (l2 = ft_strlen(s2)) ? l1 : l2);
}

char	*f_precision(t_p *params, int i)
{
	int neg;

	neg = ft_strlen(params->outneg);
	if (neg < params->precision)
	{
		while (neg < params->precision)
		{
			params->outneg = strjf(params->outneg, "0", 1, 0);
			neg++;
		}
	}
	else if (neg > params->precision)
		params->outneg = cp(params->outneg, params->precision, params->one);
	if (ft_strlen(params->outneg) > (size_t)params->precision)
	{
		params->outpos = ft_sum(params->outpos, params->one, 0, 0);
		while (params->outneg[i] != '\0')
		{
			params->outneg[i - 1] = params->outneg[i];
			i++;
		}
		params->outneg = ft_strsub(params->outneg, 0, params->precision);
	}
	return (params->outneg);
}

char	*cp(char *outneg, int prec, char *one)
{
	char *c;

	if (outneg[prec] > '4')
	{
		c = outneg;
		outneg = ft_strsub(outneg, 0, prec);
		free(c);
		c = outneg;
		outneg = ft_sum(outneg, one, 0, 0);
		free(c);
	}
	else
	{
		c = outneg;
		outneg = ft_strsub(outneg, 0, prec);
		free(c);
	}
	c = outneg;
	return (c);
}

char	*except(unsigned long m, int sign)
{
	char *out;

	if (m > 0x8000000000000000)
		out = ft_strdup("nan");
	else
	{
		out = ft_strdup("inf");
		if (sign == 1)
			out = strjf("-", out, 1, 0);
	}
	return (out);
}

int		ft_chararcmp(char *a, char *b)
{
	int i;

	i = 0;
	if (ft_strlen(a) > ft_strlen(b))
		return (1);
	if (ft_strlen(a) < ft_strlen(b))
		return (-1);
	else
	{
		while (a[i] != '\0')
		{
			if (ft_strcmp(&a[i], &b[i]) > 0)
				return (1);
			if (ft_strcmp(&a[i], &b[i]) < 0)
				return (-1);
			else
				i++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:44:48 by kysgramo          #+#    #+#             */
/*   Updated: 2020/03/03 21:45:19 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_subs	*create_subs(void)
{
	t_subs *subs;

	if (!(subs = (t_subs *)malloc(sizeof(t_subs))))
		return (NULL);
	subs->carry = 0;
	subs->rem = 0;
	subs->temp = 0;
	subs->s1 = "\0";
	subs->s2 = "\0";
	subs->l = 0;
	subs->s = 0;
	subs->out = ft_strnew(0);
	subs->remc = "\0";
	return (subs);
}

char	*ft_zerotrim(t_subs *subs)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	if (!subs->out)
		return (NULL);
	len = ft_strlen(subs->out);
	while (subs->out[i] == '0')
		i++;
	if (i == len)
	{
		free(subs->out);
		return (ft_strdup("0"));
	}
	new = ft_strnew((len - i));
	while (i < len)
	{
		new[j++] = subs->out[i++];
		new[j] = '\0';
	}
	free(subs->out);
	return (new);
}

char	*substr_loop(t_subs *subs, char *out)
{
	subs->rem = 0;
	subs->temp = 0;
	subs->temp -= subs->carry;
	if (subs->l != 0)
	{
		subs->temp = subs->temp + (subs->s1[subs->l - 1] - '0');
		subs->l--;
	}
	if (subs->s != 0)
	{
		subs->temp = subs->temp - (subs->s2[subs->s - 1] - '0');
		subs->s--;
	}
	if (subs->temp < 0)
	{
		subs->carry = 1;
		subs->rem = 10 + subs->temp;
		subs->temp = subs->rem;
	}
	else
		subs->carry = 0;
	subs->remc = ft_strnew(1);
	subs->remc[0] = subs->temp + '0';
	out = strjf(subs->remc, out, 1, 1);
	return (out);
}

char	*ft_subs1ct(char *s1, char *s2)
{
	size_t	longest;
	t_subs	*subs;
	char	*s;

	subs = create_subs();
	subs->l = ft_strlen(s1);
	subs->s = ft_strlen(s2);
	if (subs->l >= subs->s)
		longest = subs->l;
	else
	{
		free(s1);
		return (NULL);
	}
	subs->s1 = s1;
	subs->s2 = s2;
	while (longest != 0)
	{
		subs->out = substr_loop(subs, subs->out);
		longest--;
	}
	s = ft_zerotrim(subs);
	free(subs->s1);
	free(subs);
	return (s);
}

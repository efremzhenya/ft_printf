/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:51:57 by kysgramo          #+#    #+#             */
/*   Updated: 2020/03/03 21:45:19 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sum	*create_sum(void)
{
	t_sum *sum;

	if (!(sum = (t_sum *)malloc(sizeof(t_sum))))
		return (NULL);
	sum->carryc = ft_strnew(1);
	sum->carry = 0;
	sum->s = 0;
	sum->l = 0;
	return (sum);
}

t_sum	*subloop(size_t longest, t_sum *sum)
{
	unsigned int	temp;

	temp = sum->carry;
	if (sum->l != 0)
	{
		temp = temp + (sum->s1[sum->l - 1] - '0');
		sum->l--;
	}
	if (sum->s != 0)
	{
		temp = temp + (sum->s2[sum->s - 1] - '0');
		sum->s--;
	}
	if (temp >= 10)
		sum->carry = temp / 10;
	else
		sum->carry = 0;
	if (temp >= 10)
		temp = temp % 10;
	sum->out[longest - 1] = temp + '0';
	return (sum);
}

char	*sum_loop(char *s1, char *s2, t_sum *sum)
{
	size_t			longest;

	sum->l = ft_strlen(s1);
	sum->s = ft_strlen(s2);
	longest = MAX(sum->l, sum->s);
	sum->out = ft_strnew(longest);
	sum->s1 = s1;
	sum->s2 = s2;
	while (longest != 0)
	{
		sum = subloop(longest, sum);
		longest--;
	}
	if (sum->carry > 0)
	{
		sum->carryc[0] = sum->carry + '0';
		sum->out = strjf("1", sum->out, 0, 1);
	}
	return (sum->out);
}

char	*sumneg(char *s2, int diff)
{
	if (diff > 0)
		while (diff != 0)
		{
			s2 = strjf(s2, "0", 1, 0);
			diff--;
		}
	return (s2);
}

char	*ft_add(char *s1, char *s2, int negs, int clr)
{
	char			*out;
	t_sum			*sum;
	int				diff;

	diff = 0;
	diff = ft_max(s1, s2) - ft_min(s1, s2);
	sum = create_sum();
	if (negs == 1)
		s2 = sumneg(s2, diff);
	out = sum_loop(s1, s2, sum);
	if (clr == 1)
		free(s1);
	else if (clr == 2)
	{
		free(s1);
		free(s2);
	}
	else if (clr == 3)
		free(s2);
	clean_sum(sum);
	return (out);
}

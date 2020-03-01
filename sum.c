#include "ft_printf.h"

char 		*addneg(char *s2, int diff)
{
	if (diff > 0)
	{
		while (diff)
		{
			s2 = strjf(s2, '0', 1, 0);
			diff--;
		}
	}
	return (s2);
}

char		*get_sum(char *sum, char *s1, char *s2, size_t *d)
{
	size_t 	med;

	med = d[0];
	if (d[1])
	{
		med = med + s1[d[1] - 1] - '0';
		d[1]--;
	}
	if (d[2])
	{
		med = med + s2[d[2] - 1] - '0';
		d[2]--;
	}
	if (med > 9)
	{
		d[0] = med / 10;
		med = med % 10;
	}
	else
		d[0] = 0;
	sum[d[3] - 1] = med + '0';
	return (sum);
}

char		*sum_iter(char *s1, char *s2)
{
	char	*sum;
	size_t 	dump[4];

	dump[0] = 0;
	dump[1] = ft_strlen(s1);
	dump[2] = ft_strlen(s2);
	dump[3] = ft_max(s1, s2);
	sum = ft_strnew(dump[0]);
	while (dump[3])
	{
		sum = get_sum(sum, s1, s2, dump);
		dump[3]--;
	}
	if (dump[0])
		sum = strjf("1", sum, 0 , 1);
	return (sum);
}

char 		*ft_add(char *s1, char *s2, int negs, int clr)
{
	size_t diff;
	char *add;

	diff = ft_max(s1, s2) - ft_min(s1, s2);
	if (negs == 1)
		s2 = addneg(s2, diff);
	add = sum_iter(s1, s2);
	if (clr == 1)
		free(s1);
	if (clr == 2)
	{
		free(s1);
		free(s2);
	}
	if(clr == 3)
		free (s2);
	return (add);
}
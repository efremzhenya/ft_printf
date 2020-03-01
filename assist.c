
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

void	clr_float_params(t_format *params)
{
	params->left = ft_strdup("");
	params->right = ft_strdup("");
	params->zero = "0";
	params->ten = "10";
	params->one = "1";
}

char		*strjf(char *s1, char *s2, int k1, int k2)
{
	char 	*s3;
	int 	l1;
	int 	l2;

	s3 = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !s3)
		return 0;
	l1 = 0;
	while (s1[l1])
		s3[l1] = s1[l1++];
	l2 = 0;
	while (s2[l2])
		s3[l1++] = s2[l2++];
	s3[l1] = '\0';
	if (k1)
		free(s1);
	if (k2)
		free(s2);
	return (s3);
}

char		*exceptions(unsigned long m, int sign)
{
	char	*res;

	if (m == 0x8000000000000000)
		res = ft_strdup("-0");
	else if (m == 0x7fff000000000000)
		 res = sign ? ft_strdup("- inf") : ft_strdup("inf");
	else
		res = ft_strdup("NaN");
	return (res);
}

char 		*ft_ftoa(char *m, int e, t_format *param)
{
	char	*val;
	int		i;

}
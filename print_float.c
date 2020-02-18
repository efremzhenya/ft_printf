#include "ft_printf.h"

char 		*fill_bits(unsigned char *mnt)
{
	char 	*res_mnt;
	int		i;
	int		n;
	int		high_bit;

	res_mnt = ft_strnew(64);
	i = 0;
	n = 0;
	while (n < 8)
	{
		high_bit = 1;
		while (high_bit != 256)
		{
			res_mnt[i] = (mnt[n] & high_bit) ? 1 : 0;
			high_bit <<= 1;
		}
		n++;
	}
	return (res_mnt);
}
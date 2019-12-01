/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_rhs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:29:43 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/12/01 19:29:44 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "float_aux.h"
#include "ft_printf_types.h"

static char	*str_add_rightside(
	char *dst, char *src, size_t n, char *overflow)
{
	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0');
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0)
			{
				dst[n - 3] += (dst[n - 1] - '0') / 10;
				*overflow = TRUE;
			}
			else
				dst[n - 2] += (dst[n - 1] - '0') / 10;
		}
		n--;
	}
	return (dst);
}

static char	*str_half(char *str, int prcs)
{
	int	i;

	i = 0;
	while (i < prcs)
	{
		if ((str[i] - '0') % 2 == 1 && i + 1 < prcs)
			str[i + 1] = '5';
		str[i] = ((str[i] - '0') / 2) + '0';
		i++;
	}
	return (str);
}

char		*set_right_of_dot(
	char *str, int prcs, t_ld_parts ld, unsigned long i)
{
	int		exp;
	char	overflow;
	char	*buff;
	char	*frac_addr;

	frac_addr = ft_strchr(str, '.') + 1;
	buff = (char *)malloc(sizeof(char) * prcs);
	overflow = FALSE;
	while (i < LD_MANTISSA_BITS)
	{
		if ((ld.m & (1UL << (LD_MANTISSA_BITS - 1UL - i))))
		{
			exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS - 1 - i;
			buff = ft_memset(buff, '0', prcs);
			buff[0] = '5';
			while (exp < 0)
			{
				buff = str_half(buff, prcs);
				exp++;
			}
			frac_addr = str_add_rightside(frac_addr, buff, prcs, &overflow);
			if (overflow == TRUE)
			{
//				free(buff);
				buff = (char*)ft_memalloc(str - ft_strchr(str, '.'));
				buff = ft_memset(buff, '0', str - ft_strchr(str, '.'));
				str = str_add(str, buff, frac_addr - str);
				free(buff);
				buff = (char *)malloc(sizeof(char) * prcs);
			}
		}
		i++;
	}
//	free(buff);
	return (str);
}

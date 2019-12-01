/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_lhs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:29:32 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/12/01 19:29:32 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "float_aux.h"
#include "ft_printf_types.h"

char		*set_left_of_dot(
	char *str, int d_exp, t_ld_parts ld, unsigned long *i)
{
	long	exp;
	char	*buff;

	(*i) = 0;
	buff = (char *)ft_memalloc(sizeof(char) * (d_exp + 2));
	exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS;
	while (exp >= 0 && (*i) < LD_MANTISSA_BITS)
	{
		if ((ld.m & (1UL << (LD_MANTISSA_BITS - 1UL - (*i)))))
		{
			buff = ft_memset(buff, '0', d_exp + 1);
			buff[d_exp] = exp > 0 ? '2' : '1';
			exp--;
			while (exp > 0)
			{
				buff = str_add(buff, buff, d_exp + 1);
				exp--;
			}
			str = str_add(str, buff, d_exp + 1);
		}
		(*i)++;
		exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS - (*i);
	}
//	free(buff);
	return (str);
}

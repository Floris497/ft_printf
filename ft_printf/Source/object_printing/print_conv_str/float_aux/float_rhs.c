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
#include <stdio.h> //illegal

static char	*str_half(char *str, int prcs)
{
	int	i;
	int	carry;
	int	carry_tmp;

	i = 0;
	carry = FALSE;
	while (i < prcs)
	{
		carry_tmp = FALSE;
		if ((str[i] - '0') % 2 == 1)
			carry_tmp = TRUE;
		str[i] = ((str[i] - '0') / 2) + (carry ? '5' : '0');
		i++;
		carry = carry_tmp;
	}
	return (str);
}

char		*set_right_of_dot(
	char *str, int size, t_ld_parts ld, unsigned long i)
{
	int		exp;
	char	overflow;
	char	*buff;
	char	*frac_addr;
	int		len;

	frac_addr = ft_strchr(str, '.') + 1;
	len = (size - (frac_addr - str)) + 1;
	buff = (char *)ft_memalloc(sizeof(char) * (len + 1));
	overflow = FALSE;
	while (i < LD_MANTISSA_BITS)
	{
		// printf("i: %lu\n", i);
		if ((ld.m & (1UL << (LD_MANTISSA_BITS - 1UL - i))))
		{
			exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS + 1 - i;
			buff = ft_memset(buff, '0', len);
			buff[0] = '5';
			while (exp < 0)
			{
				// printf("exp: %d\nbuff pre half:\n%s\n", exp, buff);
				buff = str_half(buff, len);
				// printf("buff post half:\n%s\n", buff);
				exp++;
			}
			// printf("buff pre add:\n%s\n", buff);
			// printf("str pre add:\n%s\n", str);
			frac_addr = str_add_rightside(frac_addr, buff, len, &overflow);
			// printf("str post add:\n%s\n", str);
			if (overflow == TRUE)
			{
//				free(buff);
				buff = (char*)ft_memalloc(str - ft_strchr(str, '.'));
				buff = ft_memset(buff, '0', str - ft_strchr(str, '.'));
				str = str_add(str, buff, frac_addr - str);
				free(buff);
				buff = (char *)malloc(sizeof(char) * len);
			}
		}
		i++;
	}
//	free(buff);
	return (str);
}

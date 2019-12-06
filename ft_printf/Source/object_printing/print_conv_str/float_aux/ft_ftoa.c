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

static char        *float_special_value(t_ld_parts ld)
{
	if (ld.m == 0 && (ld.s_exp & LD_EXP) == 0)
		return ft_strdup("*0");
	if (ld.m & LD_FRACTION)
		return ft_strdup("*nan");
	return ft_strdup("*inf");
}

static int        get_dec_exp(int e)
{
	t_pf_f2u	magic_f;
	long double	ret;

	magic_f.ld.s_exp = 0x0000000000004000;
	magic_f.ld.m = 0xd49a784bcd1b8800;

	ret = e / magic_f.f;
	if (ret == 0)
		return (0);
	else if (e < 0)
		return (ret + 2);
	return (ret + 1);
}

// static int        get_dec_exp(int e)
// {
//     t_pf_f2u     magic_f;
//
//     magic_f.ld.s_exp = 0x0000000000004000;
//     magic_f.ld.m = 0xd49a784bcd1b8800;
//
//     return (e / magic_f.f);
// }

static    char    *str_round(char *str, t_ld_parts ld, int i, int prcs)
{
	int		last_i;
	char	*buff;

	last_i = (int)ft_strlen(str) - 1;
	if (!prcs)
	{
		if ((ld.m & (1 << (LD_MANTISSA_BITS - 1 - i))))
		{
			if (str[last_i] & 1 &&
				!(ld.m & ((1 << (LD_MANTISSA_BITS - 1 - i)) - 1)))
				return (str);
		}
		else
			return (str);
	}
	buff = (char*)ft_memalloc(sizeof(char) * (prcs ? prcs : last_i + 1));
	buff[prcs ? prcs : last_i] = '1';
	str = str_add(str, buff, prcs ? prcs : last_i);
	//    free(buff);
	return (str);
}

char    *ft_ftoa(t_pf_part *part)
{
	t_pf_f2u		f2u;
	int				d_exp;
	unsigned long	i;
	char			*str;
	size_t			size;

	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;
	// printf("se: %lx\nm:  %lx\n", f2u.ld.s_exp, f2u.ld.m);
	if ((f2u.ld.s_exp & LD_EXP) == LD_EXP || f2u.ld.m == 0)
		return (float_special_value(f2u.ld));

	// ft_putstr("e: ");
	// ft_putnbr((f2u.ld.s_exp & LD_EXP) - LD_EXP_BIAS);
	// ft_putchar('\n');
	d_exp = get_dec_exp((f2u.ld.s_exp & LD_EXP) - LD_EXP_BIAS);
	// ft_putstr("d_exp: ");
	// ft_putnbr(d_exp);
	// ft_putchar('\n');
	// ft_putstr("prcs: ");
	// ft_putnbr(part->prcs);
	// ft_putchar('\n');
	// size = (d_exp <= 0 ? 1 : d_exp + 1) + (part->prcs ? part->prcs + 2 : 1);
	size = (d_exp < 0 ? ft_max(LD_PRCS, -d_exp) : d_exp + LD_PRCS) + 3;
	str = (char *)ft_memalloc(sizeof(char) * size);
	str = ft_memset(str, '0', size - 1);
	str[(d_exp < 0 ? -d_exp : d_exp + 1)] = '.';
	str = set_left_of_dot(str, d_exp, f2u.ld, &i);
	// printf("part->prcs: %d\n", part->prcs);
	if (part->prcs)
		str = set_right_of_dot(str, size, f2u.ld, i);
	else
		str = str_round(str, f2u.ld, i, part->prcs);
	str[(ft_strchr(str, '.') - str) + part->prcs + (part->prcs ? 1 : 0)] = '\0';
	return (str);
}

// char    *ft_ftoa(t_pf_part *part)
// {
// 	t_pf_f2u		f2u;
// 	int				d_exp;
// 	unsigned long	i;
// 	char			*str;
// 	size_t			size;
//
// 	f2u.f = part->value.s_ld_value;
// 	f2u.ld.s_exp &= 0x000000000000FFFF;
// 	if ((f2u.ld.s_exp & LD_EXP) == LD_EXP || f2u.ld.m == 0)
// 		return (float_special_value(f2u.ld));
// 	d_exp = get_dec_exp((f2u.ld.s_exp & LD_EXP) - LD_EXP_BIAS);
// 	size = (d_exp <= 0 ? 1 : d_exp + 1) + (part->prcs ? part->prcs + 2 : 1);
// 	str = (char *)ft_memalloc(sizeof(char) * size);
// 	str = ft_memset(str, '0', size - 1);
// 	str[(d_exp < 0 ? -d_exp : d_exp + 1)] = part->prcs ? '.' : '\0';
// 	str = set_left_of_dot(str, d_exp, f2u.ld, &i);
// 	if (part->prcs)
// 		str = set_right_of_dot(str, part->prcs, f2u.ld, i);
// 	else
// 		str = str_round(str, f2u.ld, i, part->prcs);
// 	return (str);
// }

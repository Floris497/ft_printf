/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_f.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h> //illegal
#include "ft_printf_print.h"
#include "pf_print_conv.h"
#include "float_aux.h"

static char		*float_special_value(t_ld_parts ld)
{
	if (ld.m == 0 && (ld.s_exp & LD_EXP) == 0)
	{
		if (ld.s_exp & LD_SIGN)
			return ("-0");
		return ("0");
	}
	if (ld.m & LD_FRACTION)
		return ("nan");
	else if (ld.s_exp & LD_SIGN)
		return ("-inf");
	return ("inf");
}

static int		get_dec_exp(int e)
{
	size_t	dec_exp;

	dec_exp = 0;
	if (e < 0)
	{
		e *= -1;
		while (e >= 10.0)
		{
			e /= 10.0;
			dec_exp--;
		}
		return (int)(dec_exp);
	}
	while (e >= 10.0)
	{
		e /= 10.0;
		dec_exp++;
	}
	return (int)(dec_exp);
}

static	char	*str_round(char *str, t_ld_parts ld, int i, int prcs)
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
//	free(buff);
	return (str);
}

t_pf_ret		ft_printf_print_part_f(
	t_pf_obj *obj, t_pf_part *part)
{
	t_pf_f2u			f2u;
	int					d_exp;
	unsigned long		i;
	char				*str;
	size_t				size;

	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;
	// printf("se: %lx\nm:  %lx\n", f2u.ld.s_exp, f2u.ld.m);
	if ((f2u.ld.s_exp & LD_EXP) == LD_EXP || f2u.ld.m == 0)
	{
		obj->print(float_special_value(f2u.ld), LEN_NS, obj);
		return (PF_RET_SUCCESS);
	}
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
	size = (d_exp <= 0 ? 1 : d_exp + 1) + (part->prcs ? part->prcs + 2 : 1);
	str = (char *)ft_memalloc(sizeof(char) * size);
	str = ft_memset(str, '0', size - 1);
	str[(d_exp < 0 ? -d_exp : d_exp) + 1] = part->prcs ? '.' : '\0';
	str = set_left_of_dot(str, d_exp, f2u.ld, &i);
	// printf("part->prcs: %d\n", part->prcs);
	if (part->prcs)
		str = set_right_of_dot(str, part->prcs, f2u.ld, i);
	else
		str = str_round(str, f2u.ld, i, part->prcs);
	obj->print(str, LEN_NS, obj);
//	free(str);
	return (PF_RET_SUCCESS);
}

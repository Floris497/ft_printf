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
#include "ft_printf_print.h"
#include "pf_print_conv.h"

static char		*float_special_value(t_ld_parts ld)
{
	if (ld.m)
		return (ft_memdup("NaN", 4));
	else if (ld.sign_exp & LD_SIGN)
		return(ft_memdup("-Inf", 5));
	return(ft_memdup("Inf", 4));
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
		return (dec_exp);
	}
	while (e >= 10.0)
	{
		frac /= 10.0;
		dec_exp++;
	}
	return (dec_exp);
}

static char		*init_str(int sign, int prcs, int d_exp)
{
	char	*str;

	str = (char*)ft_memmalloc(sizeof(char) * (sign + abs(d_exp) + prcs + 1));
	if (prcs)
		str[abs(d_exp) + 1] = '.';
	return (str);
}

static char		*set_str(char *str, )
{
	int	i;

	i = LD_MANTISSA_BITS;
	while (i >= 0)
	{
		if (!(ld.m & 1 << i))
		{
			i--;
			continue ;
		}
		
	}
	return (str);
}

t_pf_ret		ft_printf_print_part_f(
	t_pf_obj *obj, t_pf_part *part)
{
	t_pf_f2u			f2u;
	int					d_exp;
	int					e;
	char				*str;

	f2u.f = (long double)part->value;
	if (!(f2u.ld.sign_exp & LD_EXP))
		return (special_value(f2u.ld));
	e = (ld.sign_exp & LD_EXP) - LD_EXP_BIAS;
	d_exp = get_dec_exp(ld, e);
	str = init_str(ld.sign_exp & LD_SIGN ? TRUE : FALSE, part->prcs, d_exp);
	str = set_str(str, ld);
	ft_putstr(str);
	free(str);
	return (PF_RET_SUCCESS);
}

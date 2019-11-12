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

static char		*float_special_value(unsigned long long m, unsigned long long s)
{
	if (m)
		return (ft_memdup("NaN", 4));
	else if (s)
		return(ft_memdup("-Inf", 5));
	return(ft_memdup("Inf", 4));
}

// static char		*ftoa(unsigned long s, unsigned long e, unsigned long m)
// {
// 	int			dec_exp;
// 	long double	f;
// 	char		*str;
// 	char		*dst;
//
// 	f = e >= 0 ? (long double)(1 << e) : (long double)(1 << (-e));
// 	dec_exp = 0;
// 	while (f >= 10.0)
// 	{
// 		f /= 10.0;
// 		dec_exp++;
// 	}
// 	dec_exp = e >= 0 ? dec_exp : (-dec_exp);
// 	// THIS LOSES SOME PRECISION, WHICH WILL MATTER
// 	// TRY MULTIPLYING BY HIGHEST NON-OVERFLOWING POWER OF 10
// 	// STORE IN LONG LONG INSTEAD OF INT
// 	m = (int)(m * f);
// 	str = ft_itoa(m);
// 	if (dec_exp)
// 	{
// 		dst = (char*)ft_memmalloc(dec_exp > 0 ? dec_exp + 1 : (-dec_exp) + 1);
// 		ft_memset(dst, '0', dec_exp);
// 	}
// 	if (dec_exp > 1)
// 		return (ft_strjoin(str, dst));
// 	// THIS SHOULD PLACE THE DECIMAL POINT WITHIN THE NUMBER
// 	else if (dec_exp < 0 && ft_power(10, (-dec_exp)) < m)
// 		return ("NYI");
// 	// THE NUMBER IS ALL BEHIND THE DECIMAL POINT
// 	else if (dec_exp < 0)
// 		return (ft_strjoin(ft_memdup("0.", 3), ft_strjoin(dst, str)));
// 	// THE NUMBER IS JUST THE NUMBER
// 	return(str);
// }

static char		*ft_float_to_str(t_pf_part *part)
{
	t_pf_f2u			f2u;

	f2u.f = (long double)part->value;
	if (!(f2u.u & LD_EXP))
		return (special_value(f2u.u & LD_MANTISSA, f2u.u & LD_SIGN));
	return (ftoa(f2u, part));
}

t_pf_ret		ft_printf_print_part_f(
	t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_float_to_str(part->value.s_fl_value, part->flags);
	ft_putstr(number);
	free(number);
	return (PF_RET_SUCCESS);
}

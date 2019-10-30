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

static char		*ft_float_to_str(float f)
{
	t_pf_f2u	f2u;
	int			s;
	int			e;
	int			m;

	f2u.f = f;
	s = f2u.u & SINGLE_PRECISION_SIGN;
	e = f2u.u & SINGLE_PRECISION_EXP;
	m = f2u.u & SINGLE_PRECISION_MANTISSA;
	if (e ^ SINGLE_PRECISION_EXP != 0)
	{
		if (m ^ SINGLE_PRECISION_MANTISSA != 0)
			return ("NaN");
		else if (s)
			return("-Inf");
		return("Inf");
	}
	return("NYI");
}

t_pf_ret		ft_printf_print_part_f(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_float_to_str(part->value.s_fl_value);
	pf_print_pad_conv_f(number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}

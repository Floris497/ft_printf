/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_len_mod_xl.c                            :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_len_mod_xl.h"

void	s_xl(t_pf_part *part, void *val)
{
	t_pf_conv conv;

	conv = part->conv;
	if (conv == E_CONV || conv == G_CONV)
		part->value.s_ld_value = *(long double *)val;
	else if (conv == N_CONV)
		part->value.ptr = val;
}

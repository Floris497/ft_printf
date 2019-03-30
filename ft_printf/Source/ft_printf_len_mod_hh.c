/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_len_mod_hh.c                            :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:00 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_len_mod_hh.h"

void	s_hh(t_pf_part *part, void *val)
{
	t_pf_conv conv;

	conv = part->conv;
	if (conv == O_CONV || conv == U_CONV || conv == XX_CONV || conv == X_CONV)
		part->value.u_ch_value = *(unsigned char *)val;
	else if (conv == D_CONV || conv == I_CONV || conv == C_CONV)
		part->value.s_ch_value = *(signed char *)val;
	else if (conv == S_CONV)
		part->value.s_ch_ptr_value = val;
	else if (conv == N_CONV)
		part->value.ptr = val;
}

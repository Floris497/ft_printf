/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_len_mod_ll.c                            :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:00 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_len_mod_ll.h"

void	s_ll(t_pf_part *part, void *val)
{
	t_pf_conv conv;
	
	conv = part->conv;
	if (conv == O_CONV || conv == U_CONV || conv == XX_CONV || conv == X_CONV)
		part->value.u_ll_value = *(unsigned long long *)val;
	else if (conv == D_CONV || conv == I_CONV)
		part->value.u_ll_value = *(signed long long *)val;
	else if (conv == N_CONV)
		part->value.ptr = val;
}
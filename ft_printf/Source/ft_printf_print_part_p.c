/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_p.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_part_p.h"

t_pf_ret	ft_printf_print_part_p(t_pf_obj *obj, t_pf_part *part)
{
	obj->print("<FIX IN: "__FILE__">", LEN_NS);
	if (part)
		return (PF_RET_SUCCESS);
	return (PF_RET_SUCCESS);
}

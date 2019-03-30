/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_o.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_part_o.h"

t_pf_ret	ft_printf_print_part_o(t_pf_obj *obj, t_pf_part *part)
{
	obj->print("<FIX IN: "__FILE__">");
	return (PF_RET_SUCCESS);
}

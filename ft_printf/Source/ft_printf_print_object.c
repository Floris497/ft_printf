/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_object.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_object.h"

#include "ft_printf_print_part_d.h"
#include "ft_printf_print_part_c.h"

#if DEBUG
t_pf_ret	ft_print_object_clean(t_pf_obj *obj)
{
	obj->print_clean("PLACEHOLDER");
	return (PF_RET_SUCCESS);
}
#endif

t_pf_ret	ft_print_object(t_pf_obj *obj)
{
	if (obj->part->conv == D_CONV)
		ft_printf_print_part_d(obj, obj->part);
	else if (obj->part->conv == C_CONV)
		ft_printf_print_part_c(obj, obj->part);
	else
#if DEBUG
		obj->print("<dbg_value>");
#else
		obj->print("<value>");
#endif
	return (PF_RET_SUCCESS);
}

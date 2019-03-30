/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_object.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_object.h"

#include "ft_printf_print_part_c.h"
#include "ft_printf_print_part_s.h"
#include "ft_printf_print_part_p.h"
#include "ft_printf_print_part_d.h"
#include "ft_printf_print_part_i.h"
#include "ft_printf_print_part_o.h"
#include "ft_printf_print_part_u.h"
#include "ft_printf_print_part_x.h"

#if DEBUG
t_pf_ret	ft_print_object_clean(t_pf_obj *obj)
{
	obj->print_clean("PLACEHOLDER");
	return (PF_RET_SUCCESS);
}
#endif

// cspdiouxX

t_pf_ret	ft_print_object(t_pf_obj *obj)
{
	if (obj->part->conv == C_CONV)
		ft_printf_print_part_c(obj, obj->part);
	else if (obj->part->conv == S_CONV)
		ft_printf_print_part_s(obj, obj->part);
	else if (obj->part->conv == P_CONV)
		ft_printf_print_part_p(obj, obj->part);
	else if (obj->part->conv == D_CONV)
		ft_printf_print_part_d(obj, obj->part);
	else if (obj->part->conv == I_CONV)
		ft_printf_print_part_i(obj, obj->part);
	else if (obj->part->conv == O_CONV)
		ft_printf_print_part_o(obj, obj->part);
	else if (obj->part->conv == U_CONV)
		ft_printf_print_part_u(obj, obj->part);
	else if (obj->part->conv == X_CONV || obj->part->conv == XX_CONV)
		ft_printf_print_part_x(obj, obj->part);
	else
#if DEBUG
		obj->print("<dbg_value>");
#else
		obj->print("<value>");
#endif
	return (PF_RET_SUCCESS);
}

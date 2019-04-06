/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_c.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_part_c.h"
#include "pf_print_nchar.h"

t_pf_ret	ft_printf_print_part_c(t_pf_obj *obj, t_pf_part *part)
{
	char str[2];
	
	str[0] = part->value.u_ch_value;
	str[1] = '\0';
	
	if (part->width <= 1)
	{
		obj->print(str, LEN_NS);
	}
	else
	{
		if ((part->flags & PF_MN_FLAG) != 0)
		{
			obj->print(str, LEN_NS);
			pf_print_nchar(' ', part->width - 1, obj);
		}
		else
		{
			pf_print_nchar(' ', part->width - 1, obj);
			obj->print(str, LEN_NS);
		}
	}
	return (PF_RET_SUCCESS);
}

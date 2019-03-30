/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_s.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_part_s.h"

t_pf_ret	ft_printf_print_part_s(t_pf_obj *obj, t_pf_part *part)
{
	obj->print(part->value.s_ch_ptr_value);
	return (PF_RET_SUCCESS);
}

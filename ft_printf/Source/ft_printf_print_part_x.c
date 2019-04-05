/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_x.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf_print_part_x.h"
#include "pf_print_conv_o.h"

t_pf_ret	ft_printf_print_part_x(t_pf_obj *obj, t_pf_part *part)
{
	pf_print_pad_conv_o(ft_itoa_base(16, part->value.u_ll_value), part, obj);
	return (PF_RET_SUCCESS);
}

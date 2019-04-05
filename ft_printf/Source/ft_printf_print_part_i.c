/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_i.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf_print_part_i.h"
#include "pf_print_conv_d.h"

t_pf_ret	ft_printf_print_part_i(t_pf_obj *obj, t_pf_part *part)
{
	pf_print_pad_conv_d(ft_itoa_base(10, part->value.s_ll_value), part, obj);
	return (PF_RET_SUCCESS);
}


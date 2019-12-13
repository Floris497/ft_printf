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

#include "ft_printf_print.h"

static t_pprint_function g_conversion_table[58] =
{
	NULL, NULL,
	ft_printf_print_part_c,
	ft_printf_print_part_d,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	ft_printf_print_part_u,
	NULL, NULL,
	ft_printf_print_part_x,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	ft_printf_print_part_b,
	ft_printf_print_part_c,
	ft_printf_print_part_d,
	NULL,
	ft_printf_print_part_f,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	ft_printf_print_part_o,
	NULL, NULL, NULL,
	ft_printf_print_part_s,
	NULL,
	ft_printf_print_part_u,
	NULL, NULL,
	ft_printf_print_part_x,
	NULL, NULL,
};

t_pf_ret	ft_print_object(t_pf_obj *obj)
{
	int			idx;
	t_pf_conv	conv;

	idx = 0;
	conv = obj->part->conv;
	if (conv == 0)
	{
		obj->print("<value>", LEN_NS, obj);
		return (PF_RET_FORMAT_ERROR);
	}
	while (idx < 58)
	{
		if (1 << idx == conv)
			return (g_conversion_table[idx](obj, obj->part));
		idx++;
	}
	return (PF_RET_ERROR);
}

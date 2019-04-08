/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_d.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:23 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print_part_d.h"
#include "pf_print_conv_d.h"

t_pf_ret	ft_printf_print_part_d(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_itoa_base(part->value.s_ll_value, 10);
	pf_print_pad_conv_d(number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}

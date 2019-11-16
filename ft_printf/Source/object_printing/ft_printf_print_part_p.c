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

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print.h"
#include "pf_print_conv.h"

t_pf_ret		ft_printf_print_part_p(t_pf_obj *obj, t_pf_part *part)
{
	char *str;

	str = ft_itoa_base((unsigned long long)part->value.ptr, 16);
	part->prcs = 16;
	pf_print_pad_conv_p(str, part, obj);
	free(str);
	return (PF_RET_SUCCESS);
}

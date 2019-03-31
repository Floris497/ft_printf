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

#include "ft_printf_print_part_d.h"

#include "libft.h"
#include "stdio.h" // ILLIGAL

#include "pf_print_pad.h"


t_pf_ret	ft_printf_print_part_d(t_pf_obj *obj, t_pf_part *part)
{
//	fflush(stdout);
//#if DEBUG
//	printf("print: |");
//#endif
//	printf("%*.*d", obj->part->width, obj->part->prcs, (int)obj->part->value.s_ln_value);
//#if DEBUG
//	printf("|\n");
//#endif
//	fflush(stdout);

	pf_print_pad(ft_itoa_base(10, part->value.s_ll_value), part, obj);

	return (PF_RET_SUCCESS);
}

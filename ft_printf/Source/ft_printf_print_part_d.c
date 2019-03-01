/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_d.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_part_d.h"

#include "stdio.h" // ILLIGAL

t_pf_ret	ft_printf_print_part_d(t_pf_obj *obj, t_pf_part *part)
{
	fflush(stdout);
#if DEBUG
	printf("print: |");
#endif
	printf("%*.*d", obj->part->width, obj->part->prcs, (int)obj->part->value.s_ln_value);
#if DEBUG
	printf("|\n");
#endif
	fflush(stdout);
	return (PF_RET_SUCCESS);
}

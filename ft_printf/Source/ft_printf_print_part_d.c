/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_d.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print_part_d.h"

#include "stdio.h" // ILLIGAL

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
	obj->print("<FIX IN: "__FILE__">");
	return (PF_RET_SUCCESS);
}

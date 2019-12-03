/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_f.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "float_aux.h"

t_pf_ret		ft_printf_print_part_f(t_pf_obj *obj, t_pf_part *part)
{
	char *str;

	obj->part->prcs = (obj->part->prcs == PRCS_NS ? 6 : obj->part->prcs);
	
	str = ft_ftoa(part);
	
	obj->print(str, LEN_NS, obj);
	
//	pf_print_pad_conv_f(str, part, obj);
//	free(str);
	return (PF_RET_SUCCESS);
}


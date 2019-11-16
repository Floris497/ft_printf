/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_conv_s.c                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/11/16 22:01:07 by ffredrik      #+#       #+#              */
/*   Updated: 2019/11/16 22:01:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"

static t_pf_ret	pf_print_pad_conv_c_blk
	(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lblock)
{
	if (lblock.order == SNP)
	{
		obj->print(str, 1, obj);
		pf_print_nchar(' ', lblock.pad_len, obj);
	}
	if (lblock.order == SPN)
	{
		if (part->flags & PF_ZR_FLAG)
			pf_print_nchar('0', lblock.pad_len, obj);
		else
			pf_print_nchar(' ', lblock.pad_len, obj);
		obj->print(str, 1, obj);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_c
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock lblock;

	lblock.r_prsc = (part->prcs > 1) ? part->prcs : 1;
	lblock.r_width = lblock.r_prsc;
	lblock.total_len =
		(lblock.r_width < part->width) ? part->width : lblock.r_width;
	lblock.pad_len = lblock.total_len - lblock.r_width;
	if (part->flags & PF_MN_FLAG)
		lblock.order = SNP;
	else
		lblock.order = SPN;
	pf_print_pad_conv_c_blk(str, part, obj, lblock);
	return (PF_RET_SUCCESS);
}

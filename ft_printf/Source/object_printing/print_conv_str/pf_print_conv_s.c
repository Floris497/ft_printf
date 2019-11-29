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

static t_pf_ret	pf_print_pad_conv_s_blk
	(const char *str, t_pf_obj *obj, t_lenblock lblock)
{
	if (lblock.order == SNP)
	{
		obj->print(str, lblock.r_prsc, obj);
		pf_print_nchar(' ', lblock.pad_len, obj);
	}
	else if (lblock.order == SPN)
	{
		pf_print_nchar(' ', lblock.pad_len, obj);
		obj->print(str, lblock.r_prsc, obj);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_s
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lblock;
	int			len;

	len = (int)ft_strlen(str);
	if (part->prcs == PRCS_NS)
		lblock.r_prsc = len;
	else
		lblock.r_prsc = part->prcs;
	lblock.r_prsc = (len < lblock.r_prsc ? len : lblock.r_prsc);
	if (part->width == WIDTH_NS)
		lblock.pad_len = 0;
	else
		lblock.pad_len = (part->width - lblock.r_prsc) > 0 ? (part->width - lblock.r_prsc) : 0;
	if (part->flags & PF_MN_FLAG)
		lblock.order = SNP;
	else
		lblock.order = SPN;
	pf_print_pad_conv_s_blk(str, obj, lblock);
	return (PF_RET_SUCCESS);
}

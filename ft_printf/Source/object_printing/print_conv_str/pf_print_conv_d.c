/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_conv_d.c                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/31 18:10:24 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static void		print_sign(t_pf_part *part, t_pf_obj *obj)
{
	if (part->flags & PF_SP_FLAG || part->flags & PF_PL_FLAG ||
		part->value.s_ll_value < 0)
	{
		if (part->value.s_ll_value < 0)
			obj->print("-", LEN_NS, obj);
		else
			obj->print((part->flags & PF_PL_FLAG) ? "+" : " ", LEN_NS, obj);
	}
}

static t_pf_ret	pf_print_pad_conv_d_blk
	(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lblock)
{
	if (lblock.order == SNP)
	{
		print_sign(part, obj);
		print_num_full_d(str, lblock.r_prsc, obj);
		pf_print_nchar(' ', lblock.pad_len, obj);
	}
	if (lblock.order == SPN)
	{
		print_sign(part, obj);
		pf_print_nchar('0', lblock.pad_len, obj);
		print_num_full_d(str, lblock.r_prsc, obj);
	}
	if (lblock.order == PSN)
	{
		pf_print_nchar(' ', lblock.pad_len, obj);
		print_sign(part, obj);
		print_num_full_d(str, lblock.r_prsc, obj);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_d
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock lblock;

	if (part->prcs == 0 && part->value.s_ll_value == 0)
		str = "";
	lblock.r_prsc = (int)ft_strlen(str);
	lblock.r_prsc = (part->prcs > lblock.r_prsc) ? part->prcs : lblock.r_prsc;
	lblock.r_width = lblock.r_prsc + (part->flags & PF_SP_FLAG ||
		part->flags & PF_PL_FLAG || part->value.s_ll_value < 0);
	lblock.total_len =
		(lblock.r_width < part->width) ? part->width : lblock.r_width;
	lblock.pad_len = lblock.total_len - lblock.r_width;
	if (part->flags & PF_MN_FLAG)
		lblock.order = SNP;
	else if (part->prcs != PRCS_NS)
		lblock.order = PSN;
	else if (part->flags & PF_ZR_FLAG)
		lblock.order = SPN;
	else
		lblock.order = PSN;
	pf_print_pad_conv_d_blk(str, part, obj, lblock);
	return (PF_RET_SUCCESS);
}

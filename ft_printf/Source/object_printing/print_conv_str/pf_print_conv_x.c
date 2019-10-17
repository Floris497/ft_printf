//
//  pf_print_conv_x.c
//  ft_printf
//
//  Created by Floris Fredrikze on 05/04/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static t_pf_ret	pf_print_pad_conv_x_blk(\
	const char *str, t_pf_part *part ,t_pf_obj *obj, t_lenblock lblock)
{
	if (lblock.order == SNP)
	{
		print_num_full_x(str, lblock.r_prsc, obj);
		pf_print_nchar(' ', lblock.pad_len, obj);
	}
	if (lblock.order == SPN)
	{
		if (part->flags & PF_ZR_FLAG && part->prcs == PRECIS_NS)
			pf_print_nchar('0', lblock.pad_len, obj);
		else
			pf_print_nchar(' ', lblock.pad_len, obj);
		print_num_full_x(str, lblock.r_prsc, obj);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret	pf_print_pad_conv_x(const char *str, t_pf_part *part ,t_pf_obj *obj)
{
	t_lenblock lblock;
	char *str_new;
	str_new = NULL;

	if (part->prcs == 0 && part->value.s_ll_value == 0)
		str = "";
	if (part->flags & PF_HT_FLAG && *str != '0') {
		str_new = ft_strnew(ft_strlen(str) + 2);
		(part->conv == X_CONV) ? strcpy(str_new, "0x") : strcpy(str_new, "0X");
		ft_strcat(str_new, str);
		str = str_new;
	}

	lblock.r_prsc = (int)ft_strlen(str);
	lblock.r_prsc = (part->prcs > lblock.r_prsc) ? part->prcs : lblock.r_prsc;
	lblock.r_width = lblock.r_prsc;
	lblock.total_len = (\
		lblock.r_width < part->width) ? part->width : lblock.r_width;
	lblock.pad_len = lblock.total_len - lblock.r_width;
	if (part->flags & PF_MN_FLAG)
		lblock.order = SNP;
	else
		lblock.order = SPN;
	pf_print_pad_conv_x_blk(str, part, obj, lblock);
	free(str_new);
	return (PF_RET_SUCCESS);
}

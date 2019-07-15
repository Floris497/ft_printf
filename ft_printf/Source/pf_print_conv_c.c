//
//  pf_print_conv_c.c
//  ft_printf
//
//  Created by Floris Fredrikze on 15/07/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <libft.h>
#include "pf_print_conv_c.h"
#include "pf_print_nchar.h"

static t_pf_ret	pf_print_pad_conv_c_blk(const char *str, t_pf_part *part ,t_pf_obj *obj, t_lenblock lblock)
{
	if (lblock.order == SNP) {
		obj->print(str, 1, obj);
		pf_print_nchar(' ', lblock.pad_len, obj);
	}
	if (lblock.order == SPN) {
		if (part->flags & PF_ZR_FLAG)
			pf_print_nchar('0', lblock.pad_len, obj);
		else
			pf_print_nchar(' ', lblock.pad_len, obj);
		obj->print(str, 1, obj);
	}
	return (PF_RET_SUCCESS);
}


t_pf_ret	pf_print_pad_conv_c(const char *str, t_pf_part *part ,t_pf_obj *obj)
{
	t_lenblock lblock;
	
	lblock.r_prsc = (int)ft_strlen(str);
	lblock.r_prsc = (part->prcs > lblock.r_prsc) ? part->prcs : lblock.r_prsc;
	lblock.r_width = lblock.r_prsc;
	lblock.total_len = (lblock.r_width < part->width) ? part->width : lblock.r_width;
	lblock.pad_len = lblock.total_len - lblock.r_width;
	if (part->flags & PF_MN_FLAG)
		lblock.order = SNP;
	else
		lblock.order = SPN;
	pf_print_pad_conv_c_blk(str, part, obj, lblock);
	return (PF_RET_SUCCESS);
}

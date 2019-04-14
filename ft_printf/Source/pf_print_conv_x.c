//
//  pf_print_conv_x.c
//  ft_printf
//
//  Created by Floris Fredrikze on 05/04/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_print_conv_x.h"
#include <libft.h>
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static char *pad_char(t_pf_part *part)
{
	if (part->prcs != PRECIS_NS)
		return (" ");
	else if (part->flags & PF_ZR_FLAG)
		return ("0");
	return (" ");
}

t_pf_ret	pf_print_pad_conv_x(const char *str, t_pf_part *part ,t_pf_obj *obj)
{

	int		padding;
	size_t	num_len;
	size_t	len;

	len = ft_strlen(str);

	if (part->flags & PF_HT_FLAG)
	{
		
	}

	num_len = (part->prcs > 0 && part->prcs > (int)len) ? part->prcs : len;
	padding = (part->width >= 0) ? part->width : 0;
	padding -= num_len;
	padding = (padding < 0) ? 0 : padding;


	if (part->flags & PF_MN_FLAG)
	{
		print_num_full(str, (int)num_len, obj);
		pf_print_nchar(' ', padding, obj);
	}
	else
	{
		if (pad_char(part)[0] == ' ')
		{
			pf_print_nchar(' ', padding, obj);
			print_num_full(str, (int)num_len, obj);
		}
		else if (pad_char(part)[0] == '0')
		{
			pf_print_nchar('0', padding, obj);
			print_num_full(str, (int)num_len, obj);
		}
	}
	return (PF_RET_SUCCESS);
}

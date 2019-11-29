/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_conv_x.c                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static t_pf_ret	pf_print_pad_conv_p_blk
(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	int has_prefix;

	has_prefix = (part->flags & PF_HT_FLAG);
	if (lb.order == SNP)
	{
		if (has_prefix)
			obj->print("0x", LEN_NS, obj);
		print_num_full_x(str, (has_prefix) ? lb.r_prsc - 2 : lb.r_prsc, obj);
		pf_print_nchar(' ', lb.pad_len, obj);
	}
	if (lb.order == SPN)
	{
		if (part->flags & PF_ZR_FLAG && part->prcs == PRCS_NS)
		{
			if (has_prefix)
				obj->print("0x", LEN_NS, obj);
			pf_print_nchar('0', lb.pad_len, obj);
		}
		else
		{
			pf_print_nchar(' ', lb.pad_len, obj);
			if (has_prefix)
				obj->print("0x", LEN_NS, obj);
		}
		print_num_full_x(str, (has_prefix) ? lb.r_prsc - 2 : lb.r_prsc, obj);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_p
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lb;
	size_t		len;

	len = ft_strlen(str);
	lb.r_prsc = (int)len + 2;
	lb.r_prsc = (part->prcs > lb.r_prsc) ? part->prcs : lb.r_prsc;
	lb.r_width = lb.r_prsc;
	lb.total_len = (lb.r_width < part->width) ? part->width : lb.r_width;
	lb.pad_len = lb.total_len - lb.r_width;
	if (part->flags & PF_MN_FLAG)
		lb.order = SNP;
	else
		lb.order = SPN;
	pf_print_pad_conv_p_blk(str, part, obj, lb);
	return (PF_RET_SUCCESS);
}

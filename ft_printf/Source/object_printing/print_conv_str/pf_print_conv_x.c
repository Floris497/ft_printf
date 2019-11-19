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

static t_pf_ret	pf_print_pad_conv_x_blk
(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	int has_prefix;

	has_prefix = (part->flags & PF_HT_FLAG && part->value.s_ll_value != 0);
	if (lb.order == SNP)
	{
		if (has_prefix)
			obj->print((part->conv == X_CONV) ? "0x" : "0X", LEN_NS, obj);
		print_num_full_x(str, (has_prefix) ? lb.r_prsc - 2 : lb.r_prsc, obj);
		pf_print_nchar(' ', lb.pad_len, obj);
	}
	if (lb.order == SPN)
	{
		if (part->flags & PF_ZR_FLAG && part->prcs == PRECIS_NS)
		{
			if (has_prefix)
				obj->print((part->conv == X_CONV) ? "0x" : "0X", LEN_NS, obj);
			pf_print_nchar('0', lb.pad_len, obj);
		}
		else
		{
			pf_print_nchar(' ', lb.pad_len, obj);
			if (has_prefix)
				obj->print((part->conv == X_CONV) ? "0x" : "0X", LEN_NS, obj);
		}
		print_num_full_x(str, (has_prefix) ? lb.r_prsc - 2 : lb.r_prsc, obj);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_x
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lb;
	char		*str_new;
	size_t		len;

	str_new = NULL;
	if (part->prcs == 0 && part->value.s_ll_value == 0)
		str = "";

	len = ft_strlen(str);
	lb.r_prsc = (int)len;
	lb.r_prsc = (part->prcs > lb.r_prsc) ? part->prcs : lb.r_prsc;
	if (part->flags & PF_HT_FLAG && part->value.s_ll_value != 0)
		lb.r_prsc += 2;
	lb.r_width = lb.r_prsc;
	lb.total_len = (lb.r_width < part->width) ? part->width : lb.r_width;
	lb.pad_len = lb.total_len - lb.r_width;
	if (part->flags & PF_MN_FLAG)
		lb.order = SNP;
	else
		lb.order = SPN;
	pf_print_pad_conv_x_blk(str, part, obj, lb);
	free(str_new);
	return (PF_RET_SUCCESS);
}

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

static t_pf_ret	pf_print_pad_conv_f_blk
	(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	t_pf_f2u	f2u;
	size_t		idx;

	idx = 0;
	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;

	int is_negative = (f2u.ld.s_exp & LD_SIGN);
	
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'S' && is_negative)
		{
			obj->print("-", 1, obj);
		}
		else if (lb.order[idx] == 'P')
		{
			if (part->flags & PF_ZR_FLAG && part->prcs == PRCS_NS)
				pf_print_nchar('0', lb.pad_len, obj);
			else
				pf_print_nchar(' ', lb.pad_len, obj);
		}
		else if (lb.order[idx] == 'N')
			print_num_full_d(str, lb.r_prsc, obj);
		else if (lb.order[idx] == 'D')
			obj->print(".", 1, obj);
		else if (lb.order[idx] == 'p')
			pf_print_nchar('0', part->prcs, obj);
		idx++;
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_f
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lb = {0};
	char 		*dot;
	
	if (part->prcs != 0 && (str[0] != '*' && str[1] != '0'))
	{
		dot = ft_strchr(str, '.');
		if (dot == NULL)
			lb.order = "SNDp";
	}
	
	if (lb.order == NULL)
		lb.order = "SN";
	
	pf_print_pad_conv_f_blk(*str == '*' ? str + 1 : str, part, obj, lb);
	return (PF_RET_SUCCESS);
}

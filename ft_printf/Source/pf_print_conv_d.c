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
#include "pf_print_conv_d.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full_d.h"

static const char	*is_negative(const char *str, int *is_neg)
{
	if (*str == '-')
	{
		*is_neg = 1;
		str++;
	}
	else
		*is_neg = 0;
	return str;
}

static char *pad_char(t_pf_part *part)
{
	if (part->prcs != PRECIS_NS)
		return (" ");
	else if (part->flags & PF_ZR_FLAG)
		return ("0");
	return (" ");
}

static char *sign_char(int is_neg, t_pf_part *part)
{
	if (is_neg == 1)
		return ("-");
	else if (part->flags & PF_PL_FLAG)
		return ("+");
	else if (part->flags & PF_SP_FLAG)
		return (" ");
	else
		return ("");
}

t_pf_ret	pf_print_pad_conv_d(const char *str, t_pf_part *part ,t_pf_obj *obj)
{

	int		padding;
	size_t	num_len;
	int		is_neg;
	size_t	len;

	str = is_negative(str, &is_neg);
	len = ft_strlen(str);

	num_len = (part->prcs > 0 && part->prcs > (int)len) ? part->prcs : len;
	padding = (part->width >= 0) ? part->width : 0;
	padding -= num_len + ft_strlen(sign_char(is_neg, part));
	padding = (padding < 0) ? 0 : padding;


	if (part->flags & PF_MN_FLAG)
	{
		obj->print(sign_char(is_neg, part), LEN_NS, obj);
		print_num_full_d(str, (int)num_len, obj);
		pf_print_nchar(' ', padding, obj);
	}
	else
	{
		if (pad_char(part)[0] == ' ')
		{
			pf_print_nchar(' ', padding, obj);
			obj->print(sign_char(is_neg, part), LEN_NS, obj);
			print_num_full_d(str, (int)num_len, obj);
		}
		else if (pad_char(part)[0] == '0')
		{
			obj->print(sign_char(is_neg, part), LEN_NS, obj);
			pf_print_nchar('0', padding, obj);
			print_num_full_d(str, (int)num_len, obj);
		}
	}
	return (PF_RET_SUCCESS);
}

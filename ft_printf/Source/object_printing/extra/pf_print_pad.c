/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_pad.c                                    :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_print_pad.h"
#include "pf_print_nchar.h"

static const char	*is_negative(const char *str, int *is_neg)
{
	if (*str == '-')
	{
		*is_neg = 1;
		str++;
	}
	else
		*is_neg = 0;
	return (str);
}

static char			*sign_char(int is_neg, t_pf_part *part)
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

static void			pf_print_pad_flags
	(const char *str, t_pf_part *part, t_pf_obj **obj, long *to_pad)
{
	int		is_neg;

	str = is_negative(str, &is_neg);
	if (part->flags & PF_MN_FLAG)
	{
		(*obj)->print(sign_char(is_neg, part), LEN_NS, *obj);
		(*obj)->print(str, LEN_NS, *obj);
		pf_print_nchar(' ', (size_t)(*to_pad), *obj);
	}
	else if (part->flags & PF_ZR_FLAG)
	{
		(*obj)->print(sign_char(is_neg, part), LEN_NS, *obj);
		pf_print_nchar('0', (size_t)(*to_pad), *obj);
		(*obj)->print(str, LEN_NS, *obj);
	}
	else if (part->flags & PF_PL_FLAG)
	{
		pf_print_nchar(' ', (size_t)(*to_pad), *obj);
		(*obj)->print(sign_char(is_neg, part), LEN_NS, *obj);
		(*obj)->print(str, LEN_NS, *obj);
	}
}

t_pf_ret			pf_print_pad
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	size_t	len;
	long	to_pad;
	int		is_neg;

	str = is_negative(str, &is_neg);
	len = ft_strlen(str);
	to_pad = 0;
	if (part->flags & PF_PL_FLAG || part->flags & PF_SP_FLAG || is_neg)
		to_pad--;
	if (part->prcs != 0)
		to_pad += part->width - len;
	if (part->flags & (PF_MN_FLAG | PF_ZR_FLAG | PF_PL_FLAG))
		pf_print_pad_flags(str, part, &obj, &to_pad);
	else
	{
		obj->print(sign_char(is_neg, part), LEN_NS, obj);
		obj->print(str, LEN_NS, obj);
	}
	return (PF_RET_SUCCESS);
}

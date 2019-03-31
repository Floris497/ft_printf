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
	int		is_neg;
	size_t	len;

	padding = 0;
	len = ft_strlen(str);

	str = is_negative(str, &is_neg);

	



	return (PF_RET_SUCCESS);
}

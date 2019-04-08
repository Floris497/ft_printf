/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_x.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print_part_x.h"
#include "pf_print_conv_x.h"

static t_pf_ret	change_chars(char *str, t_pf_part *part)
{
	if (part->conv == XX_CONV)
	{
		while (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str += 'A' - 'a';
			str++;
		}
	}
	else
	{
		while (*str != '\0')
		{
			if (*str >= 'A' && *str <= 'Z')
				*str -= 'A' - 'a';
			str++;
		}
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret	ft_printf_print_part_x(t_pf_obj *obj, t_pf_part *part)
{
	char *str;

	str = ft_itoa_base(part->value.u_ll_value, 16);
	change_chars(str, part);
	pf_print_pad_conv_x(str, part, obj);
	free(str);
	return (PF_RET_SUCCESS);
}

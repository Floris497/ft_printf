/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_f.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "float_aux.h"

t_pf_ret	ft_printf_print_part_f(t_pf_obj *obj, t_pf_part *part)
{
	char	*str;
	size_t	idx;

	idx = 0;
	obj->part->prcs = (obj->part->prcs == PRCS_NS ? 6 : obj->part->prcs);
	str = ft_ftoa(part);
	while (str[idx] != '\0' && (str[idx] == '0' && str[idx + 1] != '.') &&
	!(str[idx] == '0' && str[idx + 1] == '\0'))
		idx++;
	if (str[idx] == '*' && str[idx + 1] == '0')
	{
		free(str);
		str = malloc(part->prcs + 3);
		ft_memcpy(str, "0.", 2);
		ft_memset(str + 2, '0', part->prcs);
		str[part->prcs + 2] = '\0';
	}
	if (str[idx] == '*')
		part->prcs = 3;
	pf_print_pad_conv_f(&str[idx], part, obj);
	free(str);
	return (PF_RET_SUCCESS);
}

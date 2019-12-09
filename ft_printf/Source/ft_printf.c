/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf.c                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:44 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:23 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include "ft_printf_private.h"
#include "pf_fsm.h"
#include <unistd.h>

static t_pf_ret	empty_part(t_pf_part *part)
{
	part->prcs = PRCS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	part->flags = 0;
	return (PF_RET_SUCCESS);
}

t_pf_ret		print(const char *str, ssize_t n, t_pf_obj *obj)
{
	size_t		len;

	if (n == LEN_NS || n < 0)
		len = ft_strlen(str);
	else
		len = n;
	if (write(1, str, len) >= 0)
	{
		obj->chr_wrtn += len;
		return (PF_RET_SUCCESS);
	}
	return (PF_RET_WRITE_ERROR);
}

/*
** not sure about this line..
** edit: You meant the while loop.
*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_pf_obj	object;
	t_pf_part	part;

	empty_part(&part);
	object.part = &part;
	object.print = &print;
	object.chr_wrtn = 0;
	va_start(ap, format);
	object.args = &ap;
	object.input = format;
	pf_fsm_controller_state(&object);
	va_end(ap);
	return ((int)object.chr_wrtn);
}

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

#include "utils.h"
#include "ft_print_functions.h"
#include "ft_printf_types.h"
#include "pf_fsm.h"

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

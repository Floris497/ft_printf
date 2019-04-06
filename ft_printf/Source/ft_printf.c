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
#include "pf_fsm_start_state.h"

#if DEBUG
t_pf_ret	print_clean(const char *str, ssize_t n)
{
	n += n;
	ft_putstr(str);
//	ft_putnstr(str, n);
	return (PF_RET_SUCCESS);
}
#endif

t_pf_ret	print(const char *str, ssize_t n)
{
	n += n;
#if DEBUG
	ft_putstr("Print: |");
	if (!ft_isprint(*str))
		ft_putstr(" ");
	else
#endif
		ft_putstr(str);
#if DEBUG
	ft_putstr("|");
	if (!ft_isprint(*str))
		ft_putstr(" edit");
	ft_putstr("\n");
#endif
	return (PF_RET_SUCCESS);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;

	t_pf_obj object;
	object.print = &print;
#if DEBUG
	object.print_clean = &print_clean;
	object.format = format;
#endif
	va_start(ap, format);
	object.args = &ap;
	pf_fsm_start_state(format, &object);
	va_end(ap);
	return (0);
}

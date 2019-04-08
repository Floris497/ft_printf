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

t_pf_ret	print(const char *str, ssize_t n, t_pf_obj *obj)
{
	n += n;
	obj->chr_wrtn += ft_strlen(str);
	ft_putstr(str);
	return (PF_RET_SUCCESS);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;

	t_pf_obj object;
	object.print = &print;
	object.chr_wrtn = 0;
	va_start(ap, format);
	object.args = &ap;
	while (pf_fsm_start_state(format, &object) == PF_RET_HAS_MORE)
	va_end(ap);
	return ((int)object.chr_wrtn);
}

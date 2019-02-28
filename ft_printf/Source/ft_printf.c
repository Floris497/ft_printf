//
//  ft_printf.c
//  ft_printf
//
//  Created by Floris Fredrikze on 17/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "ft_printf_private.h"

#include "pf_fsm_start_state.h"
#include "libft.h"

#if DEBUG
t_pf_ret	print_clean(const char *str)
{
	ft_putstr(str);
	return (PF_RET_SUCCESS);
}
#endif


t_pf_ret	print(const char *str)
{
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

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_pf_obj object = {0};
	
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

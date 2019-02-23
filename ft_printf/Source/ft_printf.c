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

t_pf_ret	print(const char *str)
{
	ft_putstr(str);
	return (PF_RET_SUCCESS);
}

int		ft_printf(const char *format, ...)
{
	t_pf_obj object = {0};
	
	object.print = &print;
	
#if DEBUG
	object.format = format;
#endif
	
	pf_fsm_start_state(format, &object);
	
	return (0);
}

//
//  ft_printf_print_part_c.c
//  ft_printf
//
//  Created by Floris Fredrikze on 24/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "ft_printf_print_part_c.h"

t_pf_ret	ft_printf_print_part_c(t_pf_obj *obj, t_pf_part *part)
{
	char str[2];
	
	str[0] = (unsigned char)part->value.s_it_value;
	str[1] = '\0';
	
	if (part->width <= 1)
	{
		obj->print(str);
	}
	else
	{
		
	}
	
	return (PF_RET_SUCCESS);
}

//
//  ft_printf_mod_ll.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "ft_printf_mod_ll.h"

void	s_ll(t_pf_part *part, void *val)
{
	t_pf_conv conv;
	
	conv = part->conv;
	if (conv == O_CONV || conv == U_CONV || conv == XX_CONV || conv == X_CONV)
		part->u_ll_value = *(unsigned long long *)val;
	else if (conv == D_CONV || conv == I_CONV)
		part->u_ll_value = *(signed long long *)val;
	else if (conv == N_CONV)
		part->ptr = val;
}

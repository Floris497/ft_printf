//
//  ft_printf_mod_xl.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "ft_printf_mod_xl.h"

void	s_xl(t_pf_part *part, void *val)
{
	t_pf_conv conv;

	conv = part->conv;
	if (conv == E_CONV || conv == G_CONV)
		part->value.s_ld_value = *(long double *)val;
	else if (conv == N_CONV)
		part->value.ptr = val;
}

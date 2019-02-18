//
//  ft_printf_mod_hh.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "ft_printf_mod_hh.h"

void	s_hh(t_pf_part *part, void *val)
{
	t_pf_conv conv;
	
	conv = part->conv;
	if (conv == O_CONV || conv == U_CONV || conv == XX_CONV || conv == X_CONV)
		part->u_ch_value = *(unsigned char *)val;
	else if (conv == D_CONV || conv == I_CONV || conv == C_CONV)
		part->s_ch_value = *(signed char *)val;
	else if (conv == S_CONV)
		part->s_ch_ptr_value = val;
	else if (conv == N_CONV)
		part->ptr = val;
}

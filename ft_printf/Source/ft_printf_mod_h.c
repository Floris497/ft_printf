//
//  ft_printf_mod_h.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "ft_printf_mod_h.h"

void	s_h(t_pf_part *part, void *val)
{
	t_pf_conv conv;
	
	conv = part->conv;
	if (conv == O_CONV || conv == U_CONV || conv == XX_CONV || conv == X_CONV)
		part->u_sh_value = *(unsigned short *)val;
	else if (conv == D_CONV || conv == I_CONV)
		part->s_sh_value = *(signed short *)val;
	else if (conv == N_CONV)
		part->ptr = val;
}

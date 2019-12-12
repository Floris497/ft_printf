//
//  utils.c
//  ft_printf
//
//  Created by Floris Fredrikze on 12/12/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "utils.h"

t_pf_ret	empty_part(t_pf_part *part)
{
	part->prcs = PRCS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	part->flags = 0;
	return (PF_RET_SUCCESS);
}

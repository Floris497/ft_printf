//
//  ft_printf_print_part_b.c
//  ft_printf
//
//  Created by Floris Fredrikze on 09/04/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print.h"
#include "pf_print_conv.h"

t_pf_ret	ft_printf_print_part_b(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_itoa_base(part->value.u_ll_value, 2);
	pf_print_pad_conv_d(number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}

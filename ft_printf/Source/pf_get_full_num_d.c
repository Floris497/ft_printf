//
//  pf_get_full_num_d.c
//  ft_printf
//
//  Created by Floris Fredrikze on 24/04/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_get_full_num_d.h"

t_pf_ret	get_full_num_d(char **str, int num_len, t_pf_obj *obj)
{
	size_t len;
	char *new;

	len = ft_strlen(str);

	if (num_len > (int)len)
		pf_print_nchar('0', num_len - len, obj);
		obj->print(str, LEN_NS, obj);
		return (PF_RET_SUCCESS);
}

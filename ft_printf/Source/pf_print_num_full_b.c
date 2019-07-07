//
//  pf_print_num_full_b.c
//  ft_printf
//
//  Created by Floris Fredrikze on 07/07/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <libft.h>

#include "pf_print_num_full_b.h"
#include "pf_print_nchar.h"

t_pf_ret	print_num_full_b(const char *str, int num_len, t_pf_obj *obj)
{
	size_t len;
	
	len = ft_strlen(str);
	
	if (num_len > (int)len)
		pf_print_nchar('0', num_len - len, obj);
	obj->print(str, LEN_NS, obj);
	return (PF_RET_SUCCESS);
}

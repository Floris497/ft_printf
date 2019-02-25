//
//  pf_print_nchar.c
//  ft_printf
//
//  Created by Floris Fredrikze on 24/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_print_nchar.h"

t_pf_ret	pf_print_nchar(int c, size_t n, t_pf_obj *obj)
{
	char str[2];

	str[0] = (unsigned char)c;
	str[1] = '\0';
#if DEBUG
	obj->print_db(str);
#else
	obj->print(str);
#endif
	return (PF_RET_SUCCESS);
}

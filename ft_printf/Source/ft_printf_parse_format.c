//
//  ft_printf_parse_format.c
//  ft_printf
//
//  Created by Floris Fredrikze on 17/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <stddef.h>
#include "libft/libft.h"
#include "ft_printf_parse_format.h"

#include "ft_printf_parse_conv.h"
#include "ft_printf_parse_mod.h"

t_pf_ret	pf_get_part(const char *fp, t_pf_part *part ,void *val)
{
	
	t_pf_ret	rc;

	if ((rc = set_conv(part, parse_conv(fp))) < 0)
		return (rc);
		
	
	return (rc);
}

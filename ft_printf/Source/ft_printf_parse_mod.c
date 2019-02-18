//
//  ft_printf_parse_mod.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <stddef.h>
#include "libft.h"

#include "ft_printf_parse_mod.h"

t_pf_mod		parse_mod(const char *format_part)
{
	size_t	len;
	char	*loc;
	
	len = ft_strlen(format_part);

	
	return (NO_MODIFIER);
}

//t_pf_ret		set_deafault_mod(t_pf_part *part)
//{
//	if (part->conv != 0)
//	{
//		if (part->conv == D_CONV)
//		{
//			
//		}
//	}
//	if (part != NULL && mod > 0)
//		part->mod = mod;
//	else
//		return (PF_RET_FORMAT_ERROR);
//	return (0);
//}


t_pf_ret		set_mod(t_pf_part *part, t_pf_mod mod)
{
	if (part != NULL && mod > 0)
		part->mod = mod;
	else
		return (PF_RET_FORMAT_ERROR);
	return (0);
}

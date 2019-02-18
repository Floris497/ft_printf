//
//  ft_printf_parse_conv.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <stddef.h>

#include "libft/libft.h"
#include "ft_printf_parse_conv.h"

t_pf_conv	parse_conv(const char *format_part)
{
	size_t	len;
	char	*loc;
	char	conv;
	
	len = ft_strlen(format_part);
	conv = format_part[len - 1];
	
	loc = ft_memchr(PF_CONVERSION, conv, ft_strlen(PF_CONVERSION));
	
	if (loc != NULL)
		return ((t_pf_conv)(loc - PF_CONVERSION));
	else
		return (NOT_A_CONV);
}

t_pf_ret		set_conv(t_pf_part *part, t_pf_conv conv)
{
	if (part != NULL && conv > 0)
		part->conv = conv;
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}


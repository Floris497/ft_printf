//
//  ft_printf_parse_conv.c
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_CONV_H
# define FT_PRINTF_CONV_H

# include "ft_printf_types.h"

t_pf_conv		parse_conv(const char *format_part);
t_pf_ret		set_conv(t_pf_part *part, t_pf_conv conv);

#endif

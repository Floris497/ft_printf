//
//  ft_printf_parse_mod.h
//  ft_printf
//
//  Created by Floris Fredrikze on 18/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_PARSE_MOD_H
# define FT_PRINTF_PARSE_MOD_H

# include "ft_printf_types.h"

t_pf_mod		parse_mod(const char *format_part);
t_pf_ret		set_mod(t_pf_part *part, t_pf_mod mod);

#endif

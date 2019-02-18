//
//  ft_printf_parse_format.h
//  ft_printf
//
//  Created by Floris Fredrikze on 17/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_PARSE_FORMAT_H
# define FT_PRINTF_PARSE_FORMAT_H

# include "ft_printf_types.h"

t_pf_ret	pf_get_part(const char *fp, t_pf_part *part ,void *val);

#endif /* ft_printf_parse_format_h */

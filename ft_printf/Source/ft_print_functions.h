//
//  ft_print_functions.h
//  ft_printf
//
//  Created by Floris Fredrikze on 12/12/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINT_FUNCTIONS_H
# define FT_PRINT_FUNCTIONS_H

# include <string.h>
# include "ft_printf_types.h"

t_pf_ret	print(const char *str, ssize_t n, t_pf_obj *obj);

#endif

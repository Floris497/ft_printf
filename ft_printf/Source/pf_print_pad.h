//
//  pf_print_pad.h
//  ft_printf
//
//  Created by Floris Fredrikze on 25/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_PRINT_PAD_H
#define FT_PRINTF_PRINT_PAD_H

#include "ft_printf_types.h"

t_pf_ret	pf_print_pad_front(const char *str, t_pf_part *part ,t_pf_obj *obj);
t_pf_ret	pf_print_pad_back(const char *str, t_pf_part *part, t_pf_obj *obj);


#endif

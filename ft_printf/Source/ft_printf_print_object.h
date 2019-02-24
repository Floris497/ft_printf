//
//  ft_printf_print_object.h
//  ft_printf
//
//  Created by Floris Fredrikze on 24/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_PRINT_OBJECT_H
#define FT_PRINTF_PRINT_OBJECT_H

#include "ft_printf_types.h"

#if DEBUG
t_pf_ret	ft_print_object_clean(t_pf_obj *obj);
#endif

t_pf_ret	ft_print_object(t_pf_obj *obj);

#endif

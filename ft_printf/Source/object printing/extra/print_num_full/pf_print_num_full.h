//
//  pf_print_num_full.h
//  ft_printf
//
//  Created by Floris Fredrikze on 07/07/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef PRINT_NUM_FULL_H
#define PRINT_NUM_FULL_H

#include "ft_printf_types.h"

t_pf_ret	print_num_full_x(const char *str, int num_len, t_pf_obj *obj);
t_pf_ret	print_num_full_o(const char *str, int num_len, t_pf_obj *obj);
t_pf_ret	print_num_full_d(const char *str, int num_len, t_pf_obj *obj);
t_pf_ret	print_num_full_b(const char *str, int num_len, t_pf_obj *obj);

#endif

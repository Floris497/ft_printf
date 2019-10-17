//
//  pf_print_conv.h
//  ft_printf
//
//  Created by Floris Fredrikze on 05/04/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef PF_PRINT_CONV_H
# define PF_PRINT_CONV_H

# include "ft_printf_types.h"

t_pf_ret	pf_print_pad_conv_o
	(const char *str, t_pf_part *part ,t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_x
	(const char *str, t_pf_part *part ,t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_d
	(const char *str, t_pf_part *part ,t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_c
	(const char *str, t_pf_part *part ,t_pf_obj *obj);

#endif

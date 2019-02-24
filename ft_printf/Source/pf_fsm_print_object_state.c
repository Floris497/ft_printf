//
//  pf_fsm_print_object_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "db_print_struct.h"

#include "pf_fsm_print_object_state.h"
#include "ft_printf_print_object.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_start_state.h"
#include "pf_fsm_end_state.h"

t_pf_ret	pf_fsm_print_object_state(const char *input, t_pf_obj *obj)
{
#if DEBUG
	print_struct(input, obj);
#endif
	ft_print_object(obj);
	input++;
	if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else
		return (pf_fsm_start_state(input, obj));
}

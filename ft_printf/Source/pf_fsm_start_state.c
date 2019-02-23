//
//  pf_fsm_start_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 22/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_fsm_start_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_end_state.h"
#include "pf_fsm_print_char_state.h"
#include "pf_fsm_init_state.h"

t_pf_ret	pf_fsm_start_state(const char *input, t_pf_obj *obj)
{
	if (*input == '%')
		return (pf_fsm_init_state(input, obj));
	else if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else if (*input != '\0' && *input != '%')
		return (pf_fsm_print_char_state(input, obj));
	else
		return (pf_fsm_error_state(input, obj));
}

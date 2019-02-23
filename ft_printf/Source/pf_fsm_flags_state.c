//
//  pf_fsm_flags_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_fsm_flags_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_width_state.h"
#include "pf_fsm_lenght_state.h"
#include "pf_fsm_precis_state.h"
#include "pf_fsm_print_empty_object_state.h"
#include "pf_fsm_conv_state.h"

t_pf_ret	pf_fsm_flags_state(const char *input, t_pf_obj *obj)
{
#if DEBUG
	obj->error_message = NYI" - flags state has not been finished";
#endif
	return (pf_fsm_error_state(input, obj));
}

//
//  pf_fsm_init_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_fsm_init_state.h"

#include "libft.h"
#include "pf_fsm_error_state.h"
#include "pf_fsm_conv_state.h"
#include "pf_fsm_flags_state.h"
#include "pf_fsm_width_state.h"
#include "pf_fsm_precis_state.h"
#include "pf_fsm_lenght_state.h"
#include "pf_fsm_print_empty_object_state.h"

t_pf_ret			pf_fsm_init_state(const char *input, t_pf_obj *obj)
{
	
	t_pf_part part = {0};
	
	obj->part = &part;
	
	if (ft_strchr(CONV_OPTS, *(input + 1)) != NULL)
		return (pf_fsm_conv_state(input + 1, obj));
	
#if DEBUG
	obj->error_message = NYI" - init state has not been finished";
#endif
	return (pf_fsm_error_state(input, obj));
}

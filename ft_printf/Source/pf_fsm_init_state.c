//
//  pf_fsm_init_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_fsm_init_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_conv_state.h"
// include flags
// include length
// include precis
// include mods
// include print empty

t_pf_ret			pf_fsm_init_state(const char *input, t_pf_obj *obj)
{
#if DEBUG
	obj->error_message = NYI" - Init state has not been made";
#endif
	return (pf_fsm_error_state(input, obj));
}

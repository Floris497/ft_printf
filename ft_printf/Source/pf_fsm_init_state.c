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

/*
** Static var for part drastically increses call depth in FSM
*/

static t_pf_ret		empty_part(t_pf_part *part)
{
	*part = (const t_pf_part){ 0 };
	part->prcs = PRECIS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	return (PF_RET_SUCCESS);
}

t_pf_ret			pf_fsm_init_state(const char *input, t_pf_obj *obj)
{
	static t_pf_part part;

	empty_part(&part);
	obj->part = &part;
#if DEBUG
	part.start = input;
#endif
	input++;
	if (ft_strchr(CONV_OPTS, *input) != NULL)
		return (pf_fsm_conv_state(input, obj));
	else if (ft_strchr(FLAG_OPTS, *input) != NULL)
		return (pf_fsm_flags_state(input, obj));
	else if (ft_strchr(WIDTH_OPTS, *input))
		return (pf_fsm_width_state(input, obj));
	else if (ft_strchr(PRECIS_OPTS, *input))
		return (pf_fsm_precis_state(input, obj));
	else if (ft_strchr(LENG_OPTS, *input))
		return (pf_fsm_length_state(input, obj));
	else
		return (pf_fsm_print_empty_object_state(input, obj));
}

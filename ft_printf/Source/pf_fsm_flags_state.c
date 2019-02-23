//
//  pf_fsm_flags_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "pf_fsm_flags_state.h"

#include "libft.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_width_state.h"
#include "pf_fsm_lenght_state.h"
#include "pf_fsm_precis_state.h"
#include "pf_fsm_print_empty_object_state.h"
#include "pf_fsm_conv_state.h"

static t_pf_ret		set_flag(const char c, t_pf_obj *obj)
{
	if (c == '0')
		obj->part->flags |= PF_ZR_FLAG;
	else if (c == ' ')
		obj->part->flags |= PF_SP_FLAG;
	else if (c == '#')
		obj->part->flags |= PF_HT_FLAG;
	else if (c == '+')
		obj->part->flags |= PF_PL_FLAG;
	else if (c == '-')
		obj->part->flags |= PF_MN_FLAG;
	else if (c == '\'')
		obj->part->flags |= PF_AP_FLAG;
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret	pf_fsm_flags_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret	rc;
	
	rc = PF_RET_SUCCESS;
	if (ft_strchr(CONV_OPTS, *input) != NULL)
		rc = set_flag(*input, obj);
	if (rc < 0)
		return (pf_fsm_error_state(input, obj));
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
	
#if DEBUG
	obj->error_message = NYI" - flags state has not been finished";
#endif
	return (pf_fsm_error_state(input, obj));
}

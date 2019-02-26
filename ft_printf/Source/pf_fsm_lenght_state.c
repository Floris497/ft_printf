//
//  pf_fsm_lenght_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "libft.h"
#include "pf_fsm_lenght_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_conv_state.h"
#include "pf_fsm_precis_state.h"
#include "pf_fsm_width_state.h"
#include "pf_fsm_flags_state.h"
#include "pf_fsm_print_empty_object_state.h"



t_pf_len_mod			get_lenmod(const char c)
{
	if (c == 'h')
		return (H_PF_LEN_MOD);
	else if (c == 'l')
		return (L_PF_LEN_MOD);
	else if (c == 'f')
		return (L_PF_LEN_MOD);
	else if (c == 'L')
		return (XL_PF_LEN_MOD);
	else
		return (NO_LEN_MOD);
}

static t_pf_len_mod		update_lenmod(const char c, t_pf_len_mod *lenmod)
{
	if (*lenmod == LEN_MOD_NS)
		return (get_lenmod(c));
	else if (*lenmod & H_PF_LEN_MOD && get_lenmod(c) == H_PF_LEN_MOD)
		return (*lenmod |= HH_PF_LEN_MOD);
	else if (*lenmod & L_PF_LEN_MOD && get_lenmod(c) == L_PF_LEN_MOD)
		return (*lenmod |= LL_PF_LEN_MOD);
	else
		return (*lenmod |= get_lenmod(c));
}

static t_pf_ret			set_length(const char *input, t_pf_obj *obj)
{
	if (ft_strchr(LENG_OPTS, *input))
		obj->part->len_mod = update_lenmod(*input, &obj->part->len_mod);
	return (PF_RET_SUCCESS);
}

t_pf_ret	pf_fsm_length_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret rc;

	rc = PF_RET_SUCCESS;
	if (ft_strchr(LENG_OPTS, *input) != NULL)
		rc = set_length(input, obj);
	if (rc < 0)
		return (pf_fsm_error_state(input, obj));
	input++;
	if (ft_strchr(WIDTH_OPTS, *input))
		return (pf_fsm_width_state(input, obj));
	else if (ft_strchr(PRECIS_OPTS, *input))
		return (pf_fsm_precis_state(input, obj));
	else if (ft_strchr(LENG_OPTS, *input))
		return (pf_fsm_length_state(input, obj));
	if (ft_strchr(CONV_OPTS, *input) != NULL)
		return (pf_fsm_conv_state(input, obj));
	else
		return (pf_fsm_print_empty_object_state(input, obj));

#if DEBUG
	obj->error_message = NYI" - length state has not been finished";
#endif
	return (pf_fsm_error_state(input, obj));
}

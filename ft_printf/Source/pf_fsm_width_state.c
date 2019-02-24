//
//  pf_fsm_width_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include "libft.h"

#include "pf_fsm_width_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_conv_state.h"
#include "pf_fsm_precis_state.h"
#include "pf_fsm_lenght_state.h"
#include "pf_fsm_flags_state.h"
#include "pf_fsm_print_empty_object_state.h"

static t_pf_ret		set_width(const char *input, t_pf_obj *obj)
{
	char c;
	
	c = *input;
	if (ft_strchr(WIDTH_OPTS_X, *(input - 1)) == NULL)
		obj->part->width = 0;
	if (ft_strchr(WIDTH_OPTS_X, c))
	{
		if (c >= '0' && c <= '9')
		{
			obj->part->prcs *= 10;
			obj->part->prcs += (int)(c - '0');
		}
		else
		{
#if DEBUG
			obj->error_message = "NaN? How can it be?!..";
#endif
			return (PF_RET_FORMAT_ERROR);
		}
	}
	else
	{
#if DEBUG
		obj->error_message = "No char found to do something with..";
#endif
		return (PF_RET_FORMAT_ERROR);
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret	pf_fsm_width_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret	rc;
	
	rc = PF_RET_SUCCESS;
	if (ft_strchr(PRECIS_OPTS_X, *input) != NULL)
		rc = set_width(input, obj);
	if (rc < 0)
		return (pf_fsm_error_state(input, obj));
	input++;
	if (ft_strchr(CONV_OPTS, *input) != NULL)
		return (pf_fsm_conv_state(input, obj));
	else if (ft_strchr(WIDTH_OPTS_X, *input))
		return (pf_fsm_width_state(input, obj));
	else if (ft_strchr(FLAG_OPTS, *input) != NULL)
		return (pf_fsm_flags_state(input, obj));
	else if (ft_strchr(PRECIS_OPTS, *input))
		return (pf_fsm_precis_state(input, obj));
	else if (ft_strchr(LENG_OPTS, *input))
		return (pf_fsm_length_state(input, obj));
	else
		return (pf_fsm_print_empty_object_state(input, obj));
}

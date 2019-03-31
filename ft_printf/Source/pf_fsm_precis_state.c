/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_precis_state.c                             :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "pf_fsm_precis_state.h"

#include "libft.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_print_empty_object_state.h"
#include "pf_fsm_lenght_state.h"
#include "pf_fsm_flags_state.h"
#include "pf_fsm_conv_state.h"

static t_pf_ret		set_precis(const char *input, t_pf_obj *obj)
{
	char c;

	c = *input;
	if (c == '.')
		obj->part->prcs = 0;
	else if (ft_strchr(PRECIS_OPTS_X, c))
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

t_pf_ret	pf_fsm_precis_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret	rc;
	
	rc = PF_RET_SUCCESS;
	if (ft_strchr(PRECIS_OPTS_X, *input) != NULL)
		rc = set_precis(input, obj);
	if (rc < 0)
		return (pf_fsm_error_state(input, obj));
	input++;
	if (ft_strchr(CONV_OPTS, *input) != NULL)
		return (pf_fsm_conv_state(input, obj));
	else if (ft_strchr(PRECIS_OPTS_X, *input))
		return (pf_fsm_precis_state(input, obj));
	else if (ft_strchr(FLAG_OPTS, *input) != NULL)
		return (pf_fsm_flags_state(input, obj));
	else if (ft_strchr(LENG_OPTS, *input))
		return (pf_fsm_length_state(input, obj));
	else
		return (pf_fsm_print_empty_object_state(input, obj));
	
	
#if DEBUG
	obj->error_message = NYI" - precis state has not been finished";
#endif
	return (pf_fsm_error_state(input, obj));
}
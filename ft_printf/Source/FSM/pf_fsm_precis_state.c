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

#include "libft.h"
#include "pf_fsm.h"

static t_pf_ret	set_precis(t_pf_obj *obj)
{
	char c;

	c = *(obj->input);
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
			return (PF_RET_FORMAT_ERROR);
	}
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_fsm_precis_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	rc = PF_RET_SUCCESS;
	if (ft_strchr(PRECIS_OPTS_X, *(obj->input)) != NULL)
		rc = set_precis(obj);
	if (rc < 0)
		return (pf_fsm_error_state(obj));
	(obj->input)++;
	if (ft_strchr(CONV_OPTS, *(obj->input)) != NULL)
		return (pf_fsm_conv_state(obj));
	else if (ft_strchr(PRECIS_OPTS_X, *(obj->input)))
		return (pf_fsm_precis_state(obj));
	else if (ft_strchr(FLAG_OPTS, *(obj->input)) != NULL)
		return (pf_fsm_flags_state(obj));
	else if (ft_strchr(LENG_OPTS, *(obj->input)))
		return (pf_fsm_length_state(obj));
	else
		return (pf_fsm_print_empty_object_state(obj));
	return (pf_fsm_error_state(obj));
}

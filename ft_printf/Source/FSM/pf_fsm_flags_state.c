/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_flags_state.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_fsm.h"

static t_pf_ret	set_flag(const char c, t_pf_obj *obj)
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

t_pf_ret		pf_fsm_flags_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	rc = PF_RET_SUCCESS;
	if (ft_strchr(FLAG_OPTS, *(obj->input)) != NULL)
		rc = set_flag(*(obj->input), obj);
	else
		return (pf_fsm_error_state(obj));
	if (rc < 0)
		return (pf_fsm_error_state(obj));
	(obj->input)++;
	if (ft_strchr(CONV_OPTS, *(obj->input)) != NULL)
		return (pf_fsm_conv_state(obj));
	else if (ft_strchr(WIDTH_OPTS, *(obj->input)))
		return (pf_fsm_width_state(obj));
	else if (ft_strchr(FLAG_OPTS, *(obj->input)) != NULL)
		return (pf_fsm_flags_state(obj));
	else if (ft_strchr(PRECIS_OPTS, *(obj->input)))
		return (pf_fsm_precis_state(obj));
	else if (ft_strchr(LENG_OPTS, *(obj->input)))
		return (pf_fsm_length_state(obj));
	else
		return (pf_fsm_print_empty_object_state(obj));
	return (pf_fsm_error_state(obj));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_wildcard_width_state.c                     :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_fsm.h"

static t_pf_ret	set_width_wild(t_pf_obj *obj)
{
	int	value;

	if (*(obj->input) == '*')
	{
		value = (int)va_arg(*(obj->args), int);
		obj->part->width = value < 0 ? -value : value;
		if (value < 0)
			obj->part->flags |= PF_MN_FLAG;
	}
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_fsm_wildcard_width_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	if (ft_strchr(WILDCARD_OPTS, *(obj->input)) != NULL)
		rc = set_width_wild(obj);
	else
		return (PF_RET_ERROR_STATE);
	if (rc < 0)
		return (PF_RET_ERROR_STATE);
	(obj->input)++;
	if (ft_strchr(CONV_OPTS, *(obj->input)) != NULL)
		return (PF_RET_CONV_STATE);
	else if (ft_strchr(WIDTH_OPTS, *(obj->input)))
		return (PF_RET_WIDTH_STATE);
	else if (ft_strchr(FLAG_OPTS, *(obj->input)) != NULL)
		return (PF_RET_FLAGS_STATE);
	else if (ft_strchr(PRECIS_OPTS, *(obj->input)))
		return (PF_RET_PRECIS_STATE);
	else if (ft_strchr(LENG_OPTS, *(obj->input)))
		return (PF_RET_LENGTH_STATE);
	else if (ft_strchr(WILDCARD_OPTS, *(obj->input)))
		return (PF_RET_WILDCARD_WIDTH_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
	return (PF_RET_ERROR_STATE);
}

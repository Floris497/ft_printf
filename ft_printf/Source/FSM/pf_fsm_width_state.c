/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_width_state.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "pf_fsm.h"

static t_pf_ret	set_width(t_pf_obj *obj)
{
	char c;

	c = *(obj->input);
	if (ft_strchr(WIDTH_OPTS, *(obj->input - 1)) == NULL)
		obj->part->width = 0;
	if (ft_strchr(WIDTH_OPTS_X, c))
	{
		if (c >= '0' && c <= '9')
		{
			obj->part->width *= 10;
			obj->part->width += (int)(c - '0');
		}
		else
			return (PF_RET_FORMAT_ERROR);
	}
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_fsm_width_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	rc = PF_RET_SUCCESS;
	if (ft_strchr(PRECIS_OPTS_X, *(obj->input)) != NULL)
		rc = set_width(obj);
	if (rc < 0)
		return (PF_RET_ERROR_STATE);
	(obj->input)++;
	if (ft_strchr(CONV_OPTS, *(obj->input)) != NULL)
		return (PF_RET_CONV_STATE);
	else if (ft_strchr(WIDTH_OPTS_X, *(obj->input)))
		return (PF_RET_WIDTH_STATE);
	else if (ft_strchr(FLAG_OPTS, *(obj->input)) != NULL)
		return (PF_RET_FLAGS_STATE);
	else if (ft_strchr(PRECIS_OPTS, *(obj->input)))
		return (PF_RET_PRECIS_STATE);
	else if (ft_strchr(LENG_OPTS, *(obj->input)))
		return (PF_RET_LENGTH_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
}

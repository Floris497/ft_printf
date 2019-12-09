/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_init_state.c                               :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_fsm.h"

/*
** Static var for part drastically increses call depth in FSM
*/

static t_pf_ret		empty_part(t_pf_part *part)
{
	part->prcs = PRCS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	part->flags = 0;
	return (PF_RET_SUCCESS);
}

t_pf_ret			pf_fsm_init_state(t_pf_obj *obj)
{
	empty_part(obj->part);
	(obj->input)++;
	if (ft_strchr(CONV_OPTS, *(obj->input)) != NULL)
		return (PF_RET_CONV_STATE);
	else if (ft_strchr(FLAG_OPTS, *(obj->input)) != NULL)
		return (PF_RET_FLAGS_STATE);
	else if (ft_strchr(WIDTH_OPTS, *(obj->input)))
		return (PF_RET_WIDTH_STATE);
	else if (ft_strchr(PRECIS_OPTS, *(obj->input)))
		return (PF_RET_PRECIS_STATE);
	else if (ft_strchr(LENG_OPTS, *(obj->input)))
		return (PF_RET_LENGTH_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
}

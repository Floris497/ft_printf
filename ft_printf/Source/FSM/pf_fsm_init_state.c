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

#include "libft.h"
#include "pf_fsm.h"

/*
** Static var for part drastically increses call depth in FSM
*/

static t_pf_ret		empty_part(t_pf_part *part)
{
	part->prcs = PRECIS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	part->flags = 0;
	return (PF_RET_SUCCESS);
}

t_pf_ret			pf_fsm_init_state(const char *input, t_pf_obj *obj)
{
	t_pf_part part;

	empty_part(&part);
	obj->part = &part;
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

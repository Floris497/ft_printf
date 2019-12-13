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
#include "utils.h"

t_pf_ret			pf_fsm_init_state(t_pf_obj *obj)
{
	empty_part(obj->part);
	(obj->input)++;
	if (ft_slow_memchr(CONV_OPTS, *(obj->input), L_CONV_OPTS))
		return (PF_RET_CONV_STATE);
	else if (ft_slow_memchr(FLAG_OPTS, *(obj->input), L_FLAG_OPTS))
		return (PF_RET_FLAGS_STATE);
	else if (ft_slow_memchr(WIDTH_OPTS, *(obj->input), L_WIDTH_OPTS))
		return (PF_RET_WIDTH_STATE);
	else if (ft_slow_memchr(PRECIS_OPTS, *(obj->input), L_PRECIS_OPTS))
		return (PF_RET_PRECIS_STATE);
	else if (ft_slow_memchr(LENG_OPTS, *(obj->input), L_LENG_OPTS))
		return (PF_RET_LENGTH_STATE);
	else if (ft_slow_memchr(WILDCARD_OPTS, *(obj->input), L_WILDCARD_OPTS))
		return (PF_RET_WILDCARD_WIDTH_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
}

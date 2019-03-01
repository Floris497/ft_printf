/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_print_empty_object_state.c                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:13 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "db_print_struct.h"

#include "pf_fsm_print_empty_object_state.h"
#include "ft_printf_print_object.h"

#include "pf_fsm_start_state.h"
#include "pf_fsm_end_state.h"

static t_pf_ret		set_part(const char *input, t_pf_obj *obj)
{
	t_pf_part *part;
	
	part = obj->part;
	
	part->conv = C_CONV;
	part->value.s_it_value = (int)*input;
		
	return (PF_RET_SUCCESS);
}

t_pf_ret			pf_fsm_print_empty_object_state(const char *input, t_pf_obj *obj)
{
//	still have to manage some stuff..
	set_part(input, obj);
#if DEBUG
	print_struct(input, obj);
#endif
	ft_print_object(obj);
	input++;
	if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else
		return (pf_fsm_start_state(input, obj));
}

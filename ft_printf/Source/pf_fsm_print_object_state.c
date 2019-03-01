/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_print_object_state.c                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:13 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "db_print_struct.h"

#include "pf_fsm_print_object_state.h"
#include "ft_printf_print_object.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_start_state.h"
#include "pf_fsm_end_state.h"

static t_pf_ret		set_value(t_pf_obj *obj, t_pf_part *part)
{
	if (part->len_mod == HH_PF_LEN_MOD)
		part->value.s_it_value = (int)va_arg(*(obj->args), int);
	else if (part->len_mod == H_PF_LEN_MOD)
		part->value.s_it_value = (int)va_arg(*(obj->args), int);
	else if (part->len_mod == LEN_MOD_NS)
		part->value.s_it_value = (int)va_arg(*(obj->args), int);
	else if (part->len_mod == L_PF_LEN_MOD)
		part->value.s_ln_value = (long)va_arg(*(obj->args), long);
	else if (part->len_mod == LL_PF_LEN_MOD)
		part->value.s_ll_value = (long long)va_arg(*(obj->args), long long);
	else
		part->value.s_it_value = (int)va_arg(*(obj->args), int);
	return (PF_RET_SUCCESS);
}

t_pf_ret			pf_fsm_print_object_state(const char *input, t_pf_obj *obj)
{
	set_value(obj, obj->part);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_print_object_state.c                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print.h"
#include "pf_fsm.h"

static t_pf_ret		set_value_v_s(t_pf_obj *obj, t_pf_part *part)
{
	if (part->len_mod == HH_PF_LEN_MOD)
		part->value.s_ll_value = (char)va_arg(*(obj->args), long long);
	else if (part->len_mod == H_PF_LEN_MOD)
		part->value.s_ll_value = (short)va_arg(*(obj->args), long long);
	else if (part->len_mod == LEN_MOD_NS)
		part->value.s_ll_value = (int)va_arg(*(obj->args), long long);
	else if (part->len_mod == L_PF_LEN_MOD)
		part->value.s_ll_value = (long)va_arg(*(obj->args), long long);
	else if (part->len_mod == LL_PF_LEN_MOD)
		part->value.s_ll_value = (long long)va_arg(*(obj->args), long long);
	else
		part->value.s_it_value = (int)va_arg(*(obj->args), long long);
	return (PF_RET_SUCCESS);
}

// this code can be simplyfied.. va_args casting does not need to happen?
static t_pf_ret		set_value_v_u(t_pf_obj *obj, t_pf_part *part)
{
	if (part->len_mod == HH_PF_LEN_MOD)
		part->value.u_ll_value = (unsigned char)va_arg(*(obj->args), long long);
	else if (part->len_mod == H_PF_LEN_MOD)
		part->value.u_ll_value = (unsigned short)va_arg(*(obj->args), long long);
	else if (part->len_mod == LEN_MOD_NS)
		part->value.u_ll_value = (unsigned int)va_arg(*(obj->args), long long);
	else if (part->len_mod == L_PF_LEN_MOD)
		part->value.u_ll_value = (unsigned long)va_arg(*(obj->args), long long);
	else if (part->len_mod == LL_PF_LEN_MOD)
		part->value.u_ll_value = (unsigned long long)va_arg(*(obj->args), long long);
	else
		part->value.u_it_value = (unsigned int)va_arg(*(obj->args), long long);
	return (PF_RET_SUCCESS);
}

static t_pf_ret		set_value_p(t_pf_obj *obj, t_pf_part *part)
{
	part->value.s_ch_ptr_value = (char *)va_arg(*(obj->args), char *);
	return (PF_RET_SUCCESS);
}

t_pf_ret			pf_fsm_print_object_state(const char *input, t_pf_obj *obj)
{
	if (obj->part->conv == S_CONV)
		set_value_p(obj, obj->part);
	else if (obj->part->conv == U_CONV ||
			 obj->part->conv == O_CONV ||
			 obj->part->conv == X_CONV ||
			 obj->part->conv == XX_CONV)
		set_value_v_u(obj, obj->part);
	else
		set_value_v_s(obj, obj->part);

	ft_print_object(obj);
	input++;
	if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else
		return (pf_fsm_start_state(input, obj));
}

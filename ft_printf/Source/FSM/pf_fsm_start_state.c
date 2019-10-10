/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_start_state.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "pf_fsm.h"

t_pf_ret	pf_fsm_start_state(const char *input, t_pf_obj *obj)
{
	if (*input == '%')
		return (pf_fsm_init_state(input, obj));
	else if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else if (*input != '\0' && *input != '%')
		return (pf_fsm_print_char_state(input, obj));
	else
		return (pf_fsm_error_state(input, obj));
}

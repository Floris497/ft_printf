/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_print_char_state.c                         :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */


#include "pf_fsm_print_char_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_end_state.h"
#include "pf_fsm_init_state.h"

/*
** Rules
** 1: Calls init when: *[(%)]
** 2: Calls end when: *[nul]
** 3: Calls itself when: *[!(%) && !nul] | thus when no other option
*/

static t_pf_ret		write_char(const char c, t_pf_obj *obj)
{
	t_pf_ret rc;
	
	char str[2];
	str[0] = c;
	str[1] = '\0';
	rc = obj->print(str, LEN_NS, obj);
	return (rc);
}

t_pf_ret	pf_fsm_print_char_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret	rc;


	rc = PF_RET_SUCCESS;
	while (*input != '%' && *input != '\0' && rc >= 0)
	{
		rc = write_char(*input, obj);
		input++;
	}
	if (rc < 0)
		return (rc);
	if (*input == '%')
		return (pf_fsm_init_state(input, obj));
	else if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else if (*input != '\0' || *input == '%')
		return (pf_fsm_print_char_state(input, obj));
	return (pf_fsm_error_state(input, obj));
}

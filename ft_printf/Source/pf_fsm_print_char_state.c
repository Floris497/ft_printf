//
//  pf_fsm_print_char_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 22/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//


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
	rc = obj->print(str);
	if (rc >= 0)
		obj->chr_wrtn += 1;
	return (rc);
}

t_pf_ret	pf_fsm_print_char_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret	rc;
	
	rc = write_char(*input, obj);
	if (rc < 0)
		return (rc);
	input++;
	if (*input == '%')
		return (pf_fsm_init_state(input, obj));
	else if (*input == '\0')
		return (pf_fsm_end_state(input, obj));
	else if (*input != '\0' || *input == '%')
		return (pf_fsm_print_char_state(input, obj));
	return (pf_fsm_error_state(input, obj));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_flags_state.h                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FSM_FLAGS_STATE_H
#define PF_FSM_FLAGS_STATE_H

# include "ft_printf_types.h"

#define FLAG_OPTS "0 #+-'"

t_pf_ret	pf_fsm_flags_state(const char *input, t_pf_obj *obj);

#endif

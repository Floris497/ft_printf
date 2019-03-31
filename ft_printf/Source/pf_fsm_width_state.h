/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_width_state.h                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FSM_WIDTH_STATE_H
#define PF_FSM_WIDTH_STATE_H

# include "ft_printf_types.h"

#define WIDTH_OPTS "123456789"
#define WIDTH_OPTS_X "0123456789"

t_pf_ret	pf_fsm_width_state(const char *input, t_pf_obj *obj);

#endif
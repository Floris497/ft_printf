/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_init_state.h                               :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:12 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FSM_INIT_STATE_H
#define PF_FSM_INIT_STATE_H

# include "ft_printf_types.h"

# define WIDTH_NS -1
# define PRECIS_NS -1

t_pf_ret	pf_fsm_init_state(const char *input, t_pf_obj *obj);

#endif

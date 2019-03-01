/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_precis_state.h                             :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:13 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FSM_PRECIS_STATE_H
#define PF_FSM_PRECIS_STATE_H

# include "ft_printf_types.h"

# define PRECIS_OPTS "."
# define PRECIS_OPTS_X ".0123456789"


t_pf_ret	pf_fsm_precis_state(const char *input, t_pf_obj *obj);

#endif

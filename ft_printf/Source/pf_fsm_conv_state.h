//
//  pf_fsm_conv_state.h
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef PF_FSM_CONV_STATE_H
#define PF_FSM_CONV_STATE_H

# include "ft_printf_types.h"

# define CONV_OPTS "cspdioxX"

t_pf_ret	pf_fsm_conv_state(const char *input, t_pf_obj *obj);

#endif

//
//  pf_fsm_width_state.h
//  ft_printf
//
//  Created by Floris Fredrikze on 23/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef PF_FSM_WIDTH_STATE_H
#define PF_FSM_WIDTH_STATE_H

# include "ft_printf_types.h"

#define WIDTH_OPTS "123456789"
#define WIDTH_OPTS_X "0123456789"

t_pf_ret	pf_fsm_width_state(const char *input, t_pf_obj *obj);

#endif

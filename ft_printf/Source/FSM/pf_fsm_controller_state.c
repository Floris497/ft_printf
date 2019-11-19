#include "pf_fsm.h"

typedef t_pf_ret (*state_function)(t_pf_obj *);

static state_function jump_table[12] =
{
	pf_fsm_conv_state,
	pf_fsm_end_state,
	pf_fsm_error_state,
	pf_fsm_flags_state,
	pf_fsm_length_state,
	pf_fsm_precis_state,
	pf_fsm_width_state,
	pf_fsm_start_state,
	pf_fsm_print_object_state,
	pf_fsm_print_empty_object_state,
	pf_fsm_print_char_state,
	pf_fsm_init_state,
};

t_pf_ret	pf_fsm_controller_state(t_pf_obj *obj)
{
	t_pf_ret ret = PF_RET_START_STATE;

	while (ret >= 10 && ret <= 21)
	{
		ret = jump_table[ret - 10](obj);
		if (ret == PF_RET_SUCCESS && *(obj->input) != '\0')
			ret = PF_RET_START_STATE;
	}
	return (ret);
}

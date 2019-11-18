#include "pf_fsm.h"

/*

PF_RET_SUCCESS = 0,
PF_RET_HAS_MORE = 1,
PF_RET_ERROR = -1,
PF_RET_FORMAT_ERROR = -2,
PF_RET_WRITE_ERROR = -3,
PF_RET_NO_STATE_SET = -10,

PF_RET_CONV_STATE = 10,
PF_RET_END_STATE = 11,
PF_RET_ERROR_STATE = 12,
PF_RET_FLAGS_STATE = 13,
PF_RET_LENGTH_STATE = 14,
PF_RET_PRECIS_STATE = 15,
PF_RET_WIDTH_STATE = 16,
PF_RET_START_STATE = 17,
PF_RET_PRINT_OBJECT_STATE = 18,
PF_RET_PRINT_EMPTY_OBJECT_STATE = 19,
PF_RET_PRINT_CHAR_STATE = 20,
PF_RET_INIT_STATE  = 21,

*/

t_pf_ret	pf_fsm_controller_state(t_pf_obj *obj)
{
	t_pf_ret ret = PF_RET_START_STATE;

	while (ret >= 0)
	{
		if (ret >= 10) {
			if (ret == PF_RET_CONV_STATE)
				ret = pf_fsm_conv_state(obj);
			else if (ret == PF_RET_END_STATE)
				ret = pf_fsm_end_state(obj);
			else if (ret == PF_RET_ERROR_STATE)
				ret = pf_fsm_error_state(obj);
			else if (ret == PF_RET_FLAGS_STATE)
				ret = pf_fsm_flags_state(obj);
			else if (ret == PF_RET_LENGTH_STATE)
				ret = pf_fsm_length_state(obj);
			else if (ret == PF_RET_PRECIS_STATE)
				ret = pf_fsm_precis_state(obj);
			else if (ret == PF_RET_WIDTH_STATE)
				ret = pf_fsm_width_state(obj);
			else if (ret == PF_RET_START_STATE)
				ret = pf_fsm_start_state(obj);
			else if (ret == PF_RET_PRINT_OBJECT_STATE)
				ret = pf_fsm_print_object_state(obj);
			else if (ret == PF_RET_PRINT_EMPTY_OBJECT_STATE)
				ret = pf_fsm_print_empty_object_state(obj);
			else if (ret == PF_RET_PRINT_CHAR_STATE)
				ret = pf_fsm_print_char_state(obj);
			else if (ret == PF_RET_INIT_STATE)
				ret = pf_fsm_init_state(obj);
		}
		if (ret == PF_RET_SUCCESS && *(obj->input) != '\0')
			ret = PF_RET_START_STATE;
	}
	return (ret);
}

//
//  pf_fsm_error_state.c
//  ft_printf
//
//  Created by Floris Fredrikze on 22/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <execinfo.h> // ILLIGAL
#include <stdio.h> // ILLIGAL
#include <stdlib.h> // ILLIGAL

#include "pf_fsm_error_state.h"

t_pf_ret	pf_fsm_error_state(const char *input, t_pf_obj *obj)
{
	// VERRY ILLIGAL
#if DEBUG
	if (obj->error_message)
	{
		printf("Error: %s\n", obj->error_message);
		obj->error_message = NULL;
	}
#endif
	printf("Dont know what to do with: %c\nIn |%s|\n\n", *input, input);
	printf("stacktrace:\n");
	void* callstack[128];
	int i, frames = backtrace(callstack, 128);
	char** strs = backtrace_symbols(callstack, frames);
	for (i = 0; i < frames; ++i) {
		printf("%s\n", strs[i]);
	}
	free(strs);
	printf("\n");
	// END ILLIGAL
	
	return (PF_RET_NO_STATE_SET);
}


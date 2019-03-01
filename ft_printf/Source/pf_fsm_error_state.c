/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_error_state.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:12 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <execinfo.h> // ILLIGAL
#include <stdio.h> // ILLIGAL
#include <stdlib.h> // ILLIGAL
#include <string.h> // ILLIGAL

#include "pf_fsm_error_state.h"

t_pf_ret	pf_fsm_error_state(const char *input, t_pf_obj *obj)
{
	// VERRY ILLIGAL
	printf("\n");
#if DEBUG
	if (obj->error_message)
	{
		printf("Error: %s\n", obj->error_message);
		obj->error_message = NULL;
	}
	printf("\tDont know what to do with: (0x%X|%c)\n\tIn:   |%*s|\n\tFrom: |%s|\n\n", *input, *input, (int)(input - obj->format) + (int)strlen(input), input, obj->format);
#else
	printf("\tDont know what to do with: (0x%X|%c)\n\tIn: |%s|\n\n", *input, *input, input);
#endif
	printf("stacktrace:\n");
	void* callstack[128];
	int i, frames = backtrace(callstack, 128);
	char** strs = backtrace_symbols(callstack, frames);
	for (i = 0; i < frames; ++i) {
		printf("\t%s\n", strs[i]);
	}
	free(strs);
	printf("\n");
	// END ILLIGAL
	
	return (PF_RET_NO_STATE_SET);
}


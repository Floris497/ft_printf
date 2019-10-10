/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_error_state.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

//#include <execinfo.h> // ILLIGAL
//#include <stdio.h> // ILLIGAL
//#include <stdlib.h> // ILLIGAL
//#include <string.h> // ILLIGAL

#include <libft.h>
#include "pf_fsm.h"

t_pf_ret	pf_fsm_error_state(const char *input, t_pf_obj *obj)
{
	// VERRY ILLIGAL
//	printf("\n");
//	if (obj)
//		printf("");
//	printf("\tDont know what to do with: (0x%X|%c)\n\tIn: |%s|\n\n", *input, *input, input);
//	printf("stacktrace:\n");
//	void* callstack[128];
//	int i, frames = backtrace(callstack, 128);
//	char** strs = backtrace_symbols(callstack, frames);
//	for (i = 0; i < frames; ++i) {
//		printf("\t%s\n", strs[i]);
//	}
//	free(strs);
//	printf("\n");
//	// END ILLIGAL

	if (obj) {
		ft_putstr(input);
	}

	return (PF_RET_NO_STATE_SET);
}

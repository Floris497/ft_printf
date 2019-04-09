/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_conv_state.c                               :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_fsm_conv_state.h"

#include "pf_fsm_error_state.h"
#include "pf_fsm_print_object_state.h"

static t_pf_ret		set_conv(const char c, t_pf_obj *obj)
{
	if (c == 'c')
		obj->part->conv = C_CONV;
	else if (c == 's')
		obj->part->conv = S_CONV;
	else if (c == 'p')
		obj->part->conv = P_CONV;
	else if (c == 'd')
		obj->part->conv = D_CONV;
	else if (c == 'i')
		obj->part->conv = I_CONV;
	else if (c == 'o')
		obj->part->conv = O_CONV;
	else if (c == 'u')
		obj->part->conv = U_CONV;
	else if (c == 'x')
		obj->part->conv = X_CONV;
	else if (c == 'X')
		obj->part->conv = XX_CONV;
	else if (c == 'b')
		obj->part->conv = B_CONV;
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret	pf_fsm_conv_state(const char *input, t_pf_obj *obj)
{
	t_pf_ret	rc;
	
	rc = PF_RET_SUCCESS;
	if (ft_strchr(CONV_OPTS, *input) != NULL)
		rc = set_conv(*input, obj);
	if (rc < 0)
		return (pf_fsm_error_state(input, obj));
	else
		return (pf_fsm_print_object_state(input, obj));
}

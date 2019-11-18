/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_lenght_state.c                             :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_fsm.h"

t_pf_len_mod			get_lenmod(const char c)
{
	if (c == 'h')
		return (H_PF_LEN_MOD);
	else if (c == 'l')
		return (L_PF_LEN_MOD);
	else if (c == 'f')
		return (L_PF_LEN_MOD);
	else if (c == 'L')
		return (XL_PF_LEN_MOD);
	else
		return (NO_LEN_MOD);
}

static t_pf_len_mod		update_lenmod(const char c, t_pf_len_mod *lenmod)
{
	if (*lenmod == LEN_MOD_NS)
		return (get_lenmod(c));
	else if (*lenmod & H_PF_LEN_MOD && get_lenmod(c) == H_PF_LEN_MOD)
		return (*lenmod = HH_PF_LEN_MOD);
	else if (*lenmod & L_PF_LEN_MOD && get_lenmod(c) == L_PF_LEN_MOD)
		return (*lenmod = LL_PF_LEN_MOD);
	else
		return (*lenmod |= get_lenmod(c));
}

static t_pf_ret			set_length(t_pf_obj *obj)
{
	if (ft_strchr(LENG_OPTS, *(obj->input)))
		obj->part->len_mod = update_lenmod(*(obj->input), &obj->part->len_mod);
	return (PF_RET_SUCCESS);
}

t_pf_ret				pf_fsm_length_state(t_pf_obj *obj)
{
	t_pf_ret rc;

	rc = PF_RET_SUCCESS;
	if (ft_strchr(LENG_OPTS, *(obj->input)) != NULL)
		rc = set_length(obj);
	if (rc < 0)
		return (PF_RET_ERROR_STATE);
	(obj->input)++;
	if (ft_strchr(WIDTH_OPTS, *(obj->input)))
		return (PF_RET_WIDTH_STATE);
	if (ft_strchr(FLAG_OPTS, *(obj->input)))
		return (PF_RET_FLAGS_STATE);
	else if (ft_strchr(PRECIS_OPTS, *(obj->input)))
		return (PF_RET_LENGTH_STATE);
	else if (ft_strchr(LENG_OPTS, *(obj->input)))
		return (PF_RET_LENGTH_STATE);
	if (ft_strchr(CONV_OPTS, *(obj->input)) != NULL)
		return (PF_RET_CONV_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
	return (PF_RET_ERROR_STATE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_choose_length_for_mod.h                        :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef pf_choose_length_for_mod_h
#define pf_choose_length_for_mod_h

#include "ft_printf_types.h"

#define DECI_CONV (D_CONV | I_CONV | O_CONV | U_CONV | X_CONV | XX_CONV)
#define STR_CONV (C_CONV | S_CONV | P_CONV)
#define FLT_CONV (F_CONV)

t_pf_len_mod pf_get_length_for_conv(t_pf_len_mod *lenmod, t_pf_conv *conv);

#endif

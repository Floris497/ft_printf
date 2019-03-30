/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_pad.h                                    :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINT_PAD_H
#define FT_PRINTF_PRINT_PAD_H

#include "ft_printf_types.h"

t_pf_ret	pf_print_pad_front(const char *str, t_pf_part *part ,t_pf_obj *obj);
t_pf_ret	pf_print_pad_back(const char *str, t_pf_part *part, t_pf_obj *obj);


#endif

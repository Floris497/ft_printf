/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_conv_d.h                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/31 18:10:24 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_CONV_D_H
# define PF_PRINT_CONV_D_H

# include "ft_printf_types.h"

t_pf_ret	pf_print_pad_conv_d
	(const char *str, t_pf_part *part ,t_pf_obj *obj);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_object.h                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINT_OBJECT_H
#define FT_PRINTF_PRINT_OBJECT_H

#include "ft_printf_types.h"

#if DEBUG
t_pf_ret	ft_print_object_clean(t_pf_obj *obj);
#endif

t_pf_ret	ft_print_object(t_pf_obj *obj);

#endif

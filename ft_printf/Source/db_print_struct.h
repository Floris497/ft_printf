/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   db_print_struct.h                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:44 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_PRINT_STRUCT_H
# define DB_PRINT_STRUCT_H
# if DEBUG

#  include "ft_printf_types.h"

void	print_struct(const char *input, t_pf_obj *obj);

# endif
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_nchar.c                                  :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "pf_print_nchar.h"

// t_pf_ret	pf_print_nchar(int c, size_t n, t_pf_obj *obj)
// {
// 	char str[2];
//
// 	str[0] = (unsigned char)c;
// 	str[1] = '\0';
// 	while (n > 0)
// 	{
// 		obj->print(str, LEN_NS, obj);
// 		n--;
// 	}
// 	return (PF_RET_SUCCESS);
// }

t_pf_ret	pf_print_nchar(int c, size_t n, t_pf_obj *obj)
{
	char *str;

	str = (char*)malloc(sizeof(char) * n + 1);
	str[n] = '\0';
	str = ft_memset(str, c, n);
	obj->print(str, n, obj);
	return (PF_RET_SUCCESS);
}

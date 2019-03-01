/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_dictnew.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/02/10 15:00:35 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dictnew(void)
{
	t_dict *dict;

	dict = ft_memalloc(sizeof(t_dict));
	if (dict != NULL)
	{
		dict->pair = NULL;
		dict->next = NULL;
	}
	return (dict);
}

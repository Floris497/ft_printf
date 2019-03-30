/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_dictfree.c                                     :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/02/10 15:51:31 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dictfree(t_dict *dict)
{
	t_dict *next;

	if (dict != NULL)
	{
		if (dict->pair != NULL)
		{
			free(dict->pair->value);
			free(dict->pair);
		}
		next = dict->next;
		free(dict);
		dict = next;
		ft_dictfree(dict);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_lstfreeone.c                                   :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/02/08 13:59:26 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:04 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstfreeone(t_list **alst)
{
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}

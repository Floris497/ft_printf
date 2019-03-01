/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_memdel.c                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:15 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_memdel(void **ap)
{
	void *temp;

	temp = *ap;
	free(temp);
	*ap = NULL;
}

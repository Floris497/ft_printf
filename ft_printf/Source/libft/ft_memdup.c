/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_memdup.c                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:16 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:04 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t len)
{
	void	*dst;

	dst = (void *)ft_memalloc(len);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}

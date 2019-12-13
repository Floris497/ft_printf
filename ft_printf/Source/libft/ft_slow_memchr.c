/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_memchr.c                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/10 19:57:03 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/21 20:16:30 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_slow_memchr(const void *s, int c, size_t n)
{
	t_index			idx;
	unsigned char	*mem;

	mem = (unsigned char*)s;
	idx = 0;
	while (idx < n)
	{
		if (mem[idx] == (unsigned char)c)
			return ((char *)&mem[idx]);
		idx++;
	}
	return (NULL);
}

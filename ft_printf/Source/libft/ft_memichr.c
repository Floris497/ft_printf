/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_memichr.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/17 19:57:35 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memichr(const void *s, int c, size_t n)
{
	t_index			idx;
	unsigned char	*mem;

	if (s == NULL || n == 0)
		return (NULL);
	mem = (unsigned char*)s;
	idx = 0;
	while (idx < n)
	{
		if (mem[idx] != (unsigned char)c)
			return ((char *)&mem[idx]);
		idx++;
	}
	return (NULL);
}

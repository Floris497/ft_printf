/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strmap.c                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:19 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:11 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*dst;
	size_t		len;
	t_index		idx;

	len = ft_strlen(s);
	dst = ft_strnew(len);
	if (dst == NULL)
		return (dst);
	idx = 0;
	while (idx < len)
	{
		dst[idx] = f(s[idx]);
		idx++;
	}
	return (dst);
}

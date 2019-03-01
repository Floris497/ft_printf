/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strichr.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/17 19:58:18 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:11 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strichr(const char *s, int c)
{
	size_t		len;

	if (s != NULL)
	{
		len = ft_strlen(s) + 1;
		if (ft_memichr(s, c, len) != NULL)
		{
			return (ft_memichr(s, c, len));
		}
		return (NULL);
	}
	return (NULL);
}

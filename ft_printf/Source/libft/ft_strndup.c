/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strndup.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:19 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:07 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (str != NULL)
		ft_strncpy(str, s1, len);
	return (str);
}

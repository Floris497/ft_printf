/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strllen.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/17 19:58:04 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:07 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strllen(const char *s, size_t size)
{
	size_t len;

	len = 0;
	while (*s != '\0' && len < size)
	{
		len++;
		s++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strrchr.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:20 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:07 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s) + 1;
	return (ft_memrchr(s, c, len));
}

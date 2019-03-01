/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strnstr.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:20 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:12 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	long long		to_check;
	long long		idx;

	if (*needle == '\0')
		return ((char *)haystack);
	idx = 0;
	to_check = (long long)ft_strlen(haystack) - (long long)ft_strlen(needle);
	while (idx <= to_check &&
			idx < (long long)len - ((long long)ft_strlen(needle) - 1))
	{
		if (ft_memcmp(&haystack[idx], needle, ft_strlen(needle)) == 0)
			return ((char *)&haystack[idx]);
		idx++;
	}
	return (NULL);
}

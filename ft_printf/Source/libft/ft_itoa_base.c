/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_itoa_base.c                                    :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/12 18:54:33 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:23 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		char_for_number_base(unsigned int n, int type)
{
	if (n <= 9)
		return ('0' + n);
	else
		return (((type == 0) ? 'A' : 'a') + n - 10);
}

char			*ft_itoa_base(long long n, unsigned int base)
{
	char	*number;
	size_t	idx;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0)
			n = -n;
		idx = ft_log(base, n) + 1;
	}
	number = (char *)ft_memalloc(idx + 1);
	if (!number)
		return (number);
	while ((unsigned long long)n >= 1)
	{
		dst[idx - 1] = char_for_number_base(n % base, type);
		idx--;
		n /= base;
	}
	return (number);
}

char			*ft_itoa_base_sm(long long n, unsigned int base)
{
	char	*number;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0)
			len = ft_log(base, (unsigned long long)-n) + 1;
		else
			len = ft_log(base, n) + 1;
	}
	number = (char *)ft_memalloc(len + 1);
	if (!number)
		return (number);
	ft_strnbr_base_cl(n, base, number, len, 1);
	return (number);
}

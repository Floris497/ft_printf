/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_itoa_base.c                                    :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/12 18:54:33 by ffredrik      #+#       #+#              */
/*   Updated: 2019/02/07 15:40:25 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		char_for_number_base(unsigned int n)
{
	if (n <= 9)
		return ('0' + n);
	else
		return ('A' + n - 10);
}

static void		ft_strnbr_base(int n, unsigned int base, char *dst, size_t len)
{
	t_index idx;

	idx = len;
	if (n < 0)
	{
		dst[0] = '-';
		n = -n;
	}
	while ((unsigned int)n >= 1)
	{
		dst[idx - 1] = char_for_number_base(n % base);
		idx--;
		n /= base;
	}
}

char			*ft_itoa_base(unsigned int base, int n)
{
	char	*number;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0)
			len = ft_log(base, (unsigned int)-n) + 1 + 1;
		else
			len = ft_log(base, n) + 1;
	}
	number = (char *)ft_memalloc(len + 1);
	if (!number)
		return (number);
	ft_strnbr_base(n, base, number, len);
	return (number);
}

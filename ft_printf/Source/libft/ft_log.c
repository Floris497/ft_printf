/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_log.c                                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/12 18:54:33 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:23 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_log(unsigned int base, unsigned long long n)
{
	if (base == 0)
		return (0);
	if (base == 1)
		return (n - 1);
	if (n >= base)
		return (ft_log(base, n / base) + 1);
	return (0);
}

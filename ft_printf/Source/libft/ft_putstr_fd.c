/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_putstr_fd.c                                    :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:17 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:11 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	t_index idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		ft_putchar_fd(s[idx], fd);
		idx++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_putnbr_fd.c                                    :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:16 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:05 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int temp;

	if (nb < 0)
	{
		temp = -nb;
		ft_putchar_fd('-', fd);
	}
	else
		temp = nb;
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((temp % 10) + '0', fd);
}

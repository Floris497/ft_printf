/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strnew.c                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:45:20 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:07 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *string;

	string = (char *)ft_memalloc(sizeof(char) * (size + 1));
	return (string);
}

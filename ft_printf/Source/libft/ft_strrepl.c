/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_strrepl.c                                      :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/02/10 18:47:32 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/01 17:24:12 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	strrepl(char **dst, char const *src)
{
	char	*olddst;

	olddst = *dst;
	*dst = ft_strdup(src);
	free(olddst);
}

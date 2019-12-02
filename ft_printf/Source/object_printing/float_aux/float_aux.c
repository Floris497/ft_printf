/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_aux.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:30:46 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/12/01 19:30:47 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*str_add(char *dst, char *src, int n)
{
	char	*tmp;
	int		carry;

	carry = 0;
	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0') + carry;
		carry = 0;
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0)
			{
				ft_putendl("Overflow NYI");
				(void)tmp;
// 				tmp = (char*)malloc(sizeof(char) * n + 2);
// 				tmp[n + 1] = '\0';
// 				tmp[0] = (dst[n - 1] - '0') / 10;
// 				ft_strlcat(tmp, dst, n + 1);
// 				tmp[1] = ((dst[n - 1] - '0') % 10) + '0';
// //				free(dst);
// 				dst = tmp;
			}
			else
			{
				carry = (dst[n - 1] - '0') / 10;
				dst[n - 1] = ((dst[n - 1] - '0') % 10) + '0';
			}
		}
		n--;
	}
	return (dst);
}

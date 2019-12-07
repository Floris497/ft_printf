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

char	*str_add_rightside(
	char *dst, char *src, size_t n, char *overflow)
{
	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0');
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0)
			{
				dst[n - 3] += (dst[n - 1] - '0') / 10;
				*overflow = TRUE;
			}
			else
				dst[n - 2] += (dst[n - 1] - '0') / 10;
			dst[n - 1] = ((dst[n - 1] - '0') % 10) + '0';
		}
		n--;
	}
	return (dst);
}

char    *str_round(char *str, int prcs)
{
	char	*buff;
	char	*non_significant;
	char	*ptr;
	char	overflow;

	non_significant = ft_strchr(str, '.') + 1 + prcs;
	if (*non_significant <= '5')
	{
		if (*non_significant <= '4')
			return (str);
		else if (*(non_significant - (prcs == 0 ? 2 : 1)) % 2 == 0)
		{
			ptr = non_significant + 1;
			while (*ptr == '0')
				ptr++;
			if (*ptr == '\0')
				return (str);
		}
	}
	else if (!prcs)
	{
		buff = (char*)ft_memalloc(sizeof(char) * (non_significant - str));
		buff = ft_memset(buff, '0', non_significant - str - 2);
		buff[(non_significant - str) - 2] = '1';
		str = str_add(str, buff, (non_significant - str) - 1);
		//    free(buff);
		return (str);
	}
	if (!prcs)
	{
		buff = (char*)ft_memalloc(sizeof(char) * (non_significant - str));
		buff = ft_memset(buff, '0', non_significant - str - 2);
		buff[(non_significant - str) - 2] = '1';
		str = str_add(str, buff, (non_significant - str) - 1);
		//    free(buff);
		return (str);
	}
	buff = (char*)ft_memalloc(sizeof(char) * (prcs + 1));
	buff = ft_memset(buff, '0', prcs - 1);
	buff[prcs - 1] = '1';
	overflow = FALSE;
	str_add_rightside(ft_strchr(str, '.') + 1, buff, prcs, &overflow);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_f.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print.h"
#include "pf_print_conv.h"

static char		*float_special_value(t_ld_parts ld)
{
	if (ld.m)
		return (ft_memdup("NaN", 4));
	else if (ld.sign_exp & LD_SIGN)
		return(ft_memdup("-Inf", 5));
	return(ft_memdup("Inf", 4));
}

static int		get_dec_exp(int e)
{
	size_t	dec_exp;

	dec_exp = 0;
	if (e < 0)
	{
		e *= -1;
		while (e >= 10.0)
		{
			e /= 10.0;
			dec_exp--;
		}
		return (dec_exp);
	}
	while (e >= 10.0)
	{
		frac /= 10.0;
		dec_exp++;
	}
	return (dec_exp);
}

static char		*str_add(char *dst, char *src, size_t n, int *overflow)
{
	overflow = FALSE;
	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0');
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0)
			{
				overflow = TRUE;
				dst[n - (dst[n - 2] == '.' ? 3 : 2)] += (dst[n - 1] - '0') / 10;
			}
			else
				dst[n - 2] += (dst[n - 1] - '0') / 10;
		}
		n--;
	}
	return (dst);
}

static char		*set_left_of_dot(char *str, int d_exp, t_ld_parts ld, int *i)
{
	int		exp;
	char	*buff;

	(*i) = 0;
	buff = (char *)malloc(sizeof(char) * n);
	exp = (ld.sign_exp & LD_EXP) - LD_EXP_BIAS;
	while (exp >= 0 && (*i) < LD_MANTISSA_BITS)
	{
		exp = (ld.sign_exp & LD_EXP) - LD_EXP_BIAS - (*i);
		if ((ld.m & (1 << (LD_MANTISSA_BITS - (*i)))))
		{
			buff = ft_memset(buff, '0', d_exp);
			buff[d_exp - 1] = '1';
			while (exp)
			{
				buff = str_add(buff, buff, d_exp);
				exp--;
			}
			str = str_add(str, buff, d_exp);
		}
		(*i)++;
	}
	free(buff);
	return (str);
}

static char		*str_half(char *str, int prcs)
{
	int	i;

	i = 0;
	while (i < prcs)
	{
		if ((str[i] - '0') % 2 == 1 && i + 1 < prcs)
			str[i + 1] = '5';
		str[i] = ((str[i] - '0') / 2) + '0';
		i++;
	}
	return (buff);
}

static char		*set_right_of_dot(char *str, int prcs, t_ld_parts ld, int i)
{
	int		exp;
	int		overflow;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * prcs);
	while (i < LD_MANTISSA_BITS)
	{
		if ((ld.m & (1 << (LD_MANTISSA_BITS - i))))
		{
			exp = (ld.sign_exp & LD_EXP) - LD_EXP_BIAS - i;
			buff = ft_memset(buff, '0', prcs);
			buff[0] = '5';
			while (exp < 0)
			{
				buff = str_half(buff, prcs);
				exp++;
			}
			str = str_add(str, buff, prcs, &overflow);
		}
		i++;
	}
	free(buff);
	return (overflow ? str - 1 : str);
}

static	char	*str_round(char *str, t_ld_parts ld, int i)
{
	int		last_i;
	char	*buff;

	last_i = ft_strlen(str) - 1
	if (!prcs)
	{
		if ((ld.m & (1 << (LD_MANTISSA_BITS - (i + 1)))))
		{
			if (str[last_i] & 1 &&
				!(ld.m & ((1 << (LD_MANTISSA_BITS - (i + 1))) - 1)))
					return (str);
		}
		else
			return (str);
	}
	else
	{
		str = &str[last_i - prcs];
		// AAAARGH HOW TO KNOW IF ROUNDING IS NEEDED, MAYBE ROUND IN set_right_of_dot?
		// CHECK WHICH i WOULD POINT TO THE BIT IN MANTISSA CORRESPONDING WITH 2 ^ -1, AND CHECK ALL SHIT AGAIN WITH HIGHER PREC?
		// OR HAVE HIGHER PREC IN set_right_of_dot?
		// PROBABLY THAT LAST THING, CREATE THE ENTIRE BUFF.
	}
	buff = (char*)ft_memalloc(sizeof(char) * (prcs ? prcs : last_i + 1));
	buff[prcs ? prcs : last_i] = '1';
	str = str_add(str, buff, prcs ? prcs : last_i);
	free(buff);
	return (str);
}

t_pf_ret		ft_printf_print_part_f(
	t_pf_obj *obj, t_pf_part *part)
{
	t_pf_f2u			f2u;
	int					d_exp;
	int					i;
	char				*str;
	size_t				size;

	f2u.f = (long double)part->value;
	if (!(f2u.ld.sign_exp & LD_EXP))
		return (special_value(f2u.ld));
	d_exp = get_dec_exp((ld.sign_exp & LD_EXP) - LD_EXP_BIAS);
	size = (ld.sign_exp & LD_SIGN ? 1 : 0) + abs(d_exp) + part->prcs + 1;
	str = (char*)ft_memalloc(sizeof(char) * size);
	str = ft_memset(str, '0', size - 1);
	str[0] = ld.sign_exp & LD_SIGN ? '-' : '0';
	str[abs(d_exp) + 1] = part->prcs ? '.' : '\0';
	str = set_left_of_dot(ld.sign_exp & LD_SIGN ? str[1] : str, d_exp, ld, &i);
	if (part->prcs)
		str = set_right_of_dot(str[abs(d_exp) + 2], part->prcs, ld, i);
	else
		str = str_round(ld.sign_exp & LD_SIGN ? str[1] : str, ld, i);
	ft_putstr(str);
	free(str);
	return (PF_RET_SUCCESS);
}

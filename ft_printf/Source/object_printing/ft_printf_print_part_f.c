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
#include <stdio.h> //illegal
#include "ft_printf_print.h"
#include "pf_print_conv.h"

static char		*float_special_value(t_ld_parts ld)
{
	if (ld.m == 0 && (ld.s_exp & LD_EXP) == 0)
	{
		if (ld.s_exp & LD_SIGN)
			return ("-0");
		return ("0");
	}
	if (ld.m & LD_FRACTION)
		return ("nan");
	else if (ld.s_exp & LD_SIGN)
		return ("-inf");
	return ("inf");
}

static int		get_dec_exp(int e)
{
	size_t	dec_exp;

	ft_putstr("e: ");
	ft_putnbr(e);
	ft_putchar('\n');
	dec_exp = 0;
	if (e < 0)
	{
		e *= -1;
		while (e >= 10.0)
		{
			e /= 10.0;
			dec_exp--;
		}
		return (int)(dec_exp);
	}
	while (e >= 10.0)
	{
		e /= 10.0;
		dec_exp++;
	}
	return (int)(dec_exp);
}

static char		*str_add(char *dst, char *src, size_t n, char *frac_status)
{
	char	*tmp;

	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0');
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0 && *frac_status != 0)
			{
				dst[n - 3] += (dst[n - 1] - '0') / 10;
				*frac_status = 2;
			}
			else if (n - 2 < 0)
			{
				tmp = (char*)malloc(sizeof(char) * n + 2);
				tmp[n + 1] = '\0';
				tmp[0] = (dst[n - 1] - '0') / 10;
				ft_strlcat(tmp, dst, n + 1);
//				free(dst);
				dst = tmp;
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
	buff = (char *)malloc(sizeof(char) * d_exp);
	exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS;
	while (exp >= 0 && (*i) < LD_MANTISSA_BITS)
	{
		exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS - (*i);
		if ((ld.m & (1 << (LD_MANTISSA_BITS - (*i)))))
		{
			buff = ft_memset(buff, '0', d_exp);
			buff[d_exp - 1] = '1';
			while (exp)
			{
				buff = str_add(buff, buff, d_exp, "\0");
				exp--;
			}
			str = str_add(str, buff, d_exp, "\0");
		}
		(*i)++;
	}
//	free(buff);
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
	return (str);
}

static char		*set_right_of_dot(char *str, int prcs, t_ld_parts ld, int i)
{
	int		exp;
	char	frac_info;
	char	*buff;
	char	*frac_addr;

	frac_addr = ft_strchr(str, '.');
	buff = (char *)malloc(sizeof(char) * prcs);
	frac_info = 1;
	while (i < LD_MANTISSA_BITS)
	{
		if ((ld.m & (1 << (LD_MANTISSA_BITS - i))))
		{
			exp = (ld.s_exp & LD_EXP) - LD_EXP_BIAS - i;
			buff = ft_memset(buff, '0', prcs);
			buff[0] = '5';
			while (exp < 0)
			{
				buff = str_half(buff, prcs);
				exp++;
			}
			frac_addr = str_add(frac_addr, buff, prcs, &frac_info);
			if (frac_info == 2)
			{
//				free(buff);
				buff = (char*)ft_memalloc(str - ft_strchr(str, '.'));
				buff = ft_memset(buff, '0', str - ft_strchr(str, '.'));
				str = str_add(str, buff, frac_addr - str, &frac_info);
				free(buff);
				buff = (char *)malloc(sizeof(char) * prcs);
			}
		}
		i++;
	}
//	free(buff);
	return (str);
}

static	char	*str_round(char *str, t_ld_parts ld, int i, int prcs)
{
	int		last_i;
	char	*buff;

	last_i = (int)ft_strlen(str) - 1;
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
	buff = (char*)ft_memalloc(sizeof(char) * (prcs ? prcs : last_i + 1));
	buff[prcs ? prcs : last_i] = '1';
	str = str_add(str, buff, prcs ? prcs : last_i, "\0");
//	free(buff);
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

	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;
	printf("se: %lx\nm:  %lx\n", f2u.ld.s_exp, f2u.ld.m);
	if ((f2u.ld.s_exp & LD_EXP) == LD_EXP || f2u.ld.m == 0)
	{
		obj->print(float_special_value(f2u.ld), LEN_NS, obj);
		return (PF_RET_SUCCESS);
	}
	d_exp = get_dec_exp((f2u.ld.s_exp & LD_EXP) - LD_EXP_BIAS);
	ft_putstr("d_exp: ");
	ft_putnbr(d_exp);
	ft_putchar('\n');
	size = (d_exp < 0 ? -d_exp : d_exp) + (part->prcs ? part->prcs + 2 : 1);
	str = (char *)ft_memalloc(sizeof(char) * size);
	str = ft_memset(str, '0', size - 1);
	str[(d_exp < 0 ? -d_exp : d_exp) + 1] = part->prcs ? '.' : '\0';
	str = set_left_of_dot(str, d_exp, f2u.ld, &i);
	if (part->prcs)
		str = set_right_of_dot(str, part->prcs, f2u.ld, i);
	else
		str = str_round(str, f2u.ld, i, part->prcs);
	obj->print(str, LEN_NS, obj);
//	free(str);
	return (PF_RET_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   main.c                                            :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:44 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <float.h>

int main(int argc, const char *argv[])
{

	printf("\nFloats:\n\n");

	printf("pf: %.2f|\n", 0.0/0.0);
	ft_printf("ft: %.2f|\n\n", 0.0/0.0);

	printf("pf: %.2f|\n", 2.0/0.0);
	ft_printf("ft: %.2f|\n\n", 2.0/0.0);

	printf("pf: %.2f|\n", -2.0/0.0);
	ft_printf("ft: %.2f|\n\n", -2.0/0.0);

	printf("pf: %f|\n", -0.0);
	ft_printf("ft: %f|\n\n", -0.0);

	printf("pf: %f|\n", 0.0);
	ft_printf("ft: %f|\n\n", 0.0);

	printf("pf: %f|\n", 1.0);
	ft_printf("ft: %f|\n\n", 1.0);

	printf("pf: %.20f|\n", 1.0);
	ft_printf("ft: %.20f|\n\n", 1.0);

	printf("pf: %.6f|\n", 1.0);
	ft_printf("ft: %.6f|\n\n", 1.0);

	printf("pf: %.0f|\n", 2.0);
	ft_printf("ft: %.0f|\n\n", 2.0);

	printf("pf: %.0f|\n", 4.0);
	ft_printf("ft: %.0f|\n\n", 4.0);

	printf("pf: %.0f|\n", 500.0);
	ft_printf("ft: %.0f|\n\n", 500.0);

	printf("pf: %.0f|\n", 2.5);
	ft_printf("ft: %.0f|\n\n", 2.5);

	printf("pf: %.0f|\n", 3.5);
	ft_printf("ft: %.0f|\n\n", 3.5);

	printf("pf: %.1f|\n", 0.25);
	ft_printf("ft: %.1f|\n\n", 0.25);

	printf("pf: %.1f|\n", 0.35);
	ft_printf("ft: %.1f|\n\n", 0.35);

	printf("pf: %.1f|\n", 0.75);
	ft_printf("ft: %.1f|\n\n", 0.75);

	printf("pf: %.2f|\n", -0.125);
	ft_printf("ft: %.2f|\n\n", -0.125);

	printf("pf: %f|\n", 0.025);
	ft_printf("ft: %f|\n\n", 0.025);

	printf("pf: %f|\n", -0.00125);
	ft_printf("ft: %f|\n\n", -0.00125);

	printf("pf: %f|\n", 100000000.0);
	ft_printf("ft: %f|\n\n", 100000000.0);

	printf("pf: %f|\n", 3.9999999);
	ft_printf("ft: %f|\n\n", 3.9999999);

	printf("pf: %.20f|\n", 1.025978542436587568678);
	ft_printf("ft: %.20f|\n\n", 1.025978542436587568678);

	printf("pf: %.20f|\n", 1.025978548534310422034);
	ft_printf("ft: %.20f|\n\n", 1.025978548534310422034);

	printf("pf: %f|\n", 7.0/11.0);
	ft_printf("ft: %f|\n\n", 7.0/11.0);

	printf("pf: %.20f|\n", 7.0/11.0);
	ft_printf("ft: %.20f|\n\n", 7.0/11.0);

	printf("FLT values\n\n");

	printf("pf: %f|\n", FLT_MIN);
	ft_printf("ft: %f|\n\n", FLT_MIN);

	printf("pf: %f|\n", -FLT_MIN);
	ft_printf("ft: %f|\n\n", -FLT_MIN);

	printf("pf: %f|\n", FLT_MAX);
	ft_printf("ft: %f|\n\n", FLT_MAX);

	printf("pf: %f|\n", -FLT_MAX);
	ft_printf("ft: %f|\n\n", -FLT_MAX);

	printf("pf: %.0f|\n", FLT_MIN);
	ft_printf("ft: %.0f|\n\n", FLT_MIN);

	printf("pf: %.0f|\n", -FLT_MIN);
	ft_printf("ft: %.0f|\n\n", -FLT_MIN);

	printf("pf: %.0f|\n", FLT_MAX);
	ft_printf("ft: %.0f|\n\n", FLT_MAX);

	printf("pf: %.0f|\n", -FLT_MAX);
	ft_printf("ft: %.0f|\n\n", -FLT_MAX);

	printf("pf: %f|\n", FLT_TRUE_MIN);
	ft_printf("ft: %f|\n\n", FLT_TRUE_MIN);

	printf("pf: %f|\n", -FLT_TRUE_MIN);
	ft_printf("ft: %f|\n\n", -FLT_TRUE_MIN);

	printf("DBL values\n\n");

	printf("pf: %lf|\n", DBL_MIN);
	ft_printf("ft: %lf|\n\n", DBL_MIN);

	printf("pf: %lf|\n", -DBL_MIN);
	ft_printf("ft: %lf|\n\n", -DBL_MIN);

	printf("pf: %lf|\n", DBL_MAX);
	ft_printf("ft: %lf|\n\n", DBL_MAX);

	printf("pf: %lf|\n", -DBL_MAX);
	ft_printf("ft: %lf|\n\n", -DBL_MAX);

	printf("pf: %.0lf|\n", DBL_MIN);
	ft_printf("ft: %.0lf|\n\n", DBL_MIN);

	printf("pf: %.0lf|\n", -DBL_MIN);
	ft_printf("ft: %.0lf|\n\n", -DBL_MIN);

	printf("pf: %.0lf|\n", DBL_MAX);
	ft_printf("ft: %.0lf|\n\n", DBL_MAX);

	printf("pf: %.0lf|\n", -DBL_MAX);
	ft_printf("ft: %.0lf|\n\n", -DBL_MAX);

	printf("pf: %lf|\n", DBL_TRUE_MIN);
	ft_printf("ft: %lf|\n\n", DBL_TRUE_MIN);

	printf("pf: %lf|\n", -DBL_TRUE_MIN);
	ft_printf("ft: %lf|\n\n", -DBL_TRUE_MIN);

	printf("LDBL values\n\n");

	printf("pf: %Lf|\n", LDBL_MIN);
	ft_printf("ft: %Lf|\n\n", LDBL_MIN);

	printf("pf: %Lf|\n", -LDBL_MIN);
	ft_printf("ft: %Lf|\n\n", -LDBL_MIN);

	printf("pf: %Lf|\n", LDBL_MAX);
	ft_printf("ft: %Lf|\n\n", LDBL_MAX);

	printf("pf: %Lf|\n", -LDBL_MAX);
	ft_printf("ft: %Lf|\n\n", -LDBL_MAX);

	printf("pf: %.0Lf|\n", LDBL_MIN);
	ft_printf("ft: %.0Lf|\n\n", LDBL_MIN);

	printf("pf: %.0Lf|\n", -LDBL_MIN);
	ft_printf("ft: %.0Lf|\n\n", -LDBL_MIN);

	printf("pf: %.0Lf|\n", LDBL_MAX);
	ft_printf("ft: %.0Lf|\n\n", LDBL_MAX);

	printf("pf: %.0Lf|\n", -LDBL_MAX);
	ft_printf("ft: %.0Lf|\n\n", -LDBL_MAX);

	printf("pf: %Lf|\n", LDBL_TRUE_MIN);
	ft_printf("ft: %Lf|\n\n", LDBL_TRUE_MIN);

	printf("pf: %Lf|\n", -LDBL_TRUE_MIN);
	ft_printf("ft: %Lf|\n\n", -LDBL_TRUE_MIN);

	printf("pf: %.15f|\n", 2.0/0.0);
	ft_printf("ft: %.15f|\n\n", 2.0/0.0);

	printf("pf: %-.15f|\n", 2.0/0.0);
	ft_printf("ft: %-.15f|\n\n", 2.0/0.0);

	printf("pf: %10.2f|\n", 2.0/0.0);
	ft_printf("ft: %10.2f|\n\n", 2.0/0.0);

	printf("pf: %-10.2f|\n", 2.0/0.0);
	ft_printf("ft: %-10.2f|\n\n", 2.0/0.0);

	printf("pf: %.2f|\n", -2.0/0.0);
	ft_printf("ft: %.2f|\n\n", -2.0/0.0);

	printf("pf: %.100f|\n", 0.237);
	ft_printf("ft: %.100f|\n\n", 0.237);

	printf("pf: %.2000f|\n", 632.28376510723481);
	ft_printf("ft: %.2000f|\n\n", 632.28376510723481);

	printf("pf: %.23f|\n", 632.28376510723481);
	ft_printf("ft: %.23f|\n\n", 632.28376510723481);

	printf("pf: %.24f|\n", 632.28376510723481);
	ft_printf("ft: %.24f|\n\n", 632.28376510723481);

	printf("pf: %.25f|\n", 632.28376510723481);
	ft_printf("ft: %.25f|\n\n", 632.28376510723481);

	printf("pf: %.26f|\n", 632.28376510723481);
	ft_printf("ft: %.26f|\n\n", 632.28376510723481);

	printf("pf: %.27f|\n", 632.28376510723481);
	ft_printf("ft: %.27f|\n\n", 632.28376510723481);

	return (0);
}

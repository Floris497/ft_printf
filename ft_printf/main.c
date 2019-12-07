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

void run_code()
{
	ft_printf("||");
	ft_printf("|%3 hallo|", 1);
	ft_printf("|%19 -.4f|", 1.0);
	ft_printf("|%2+0%|");
	ft_printf("|%2 2%|");
	ft_printf("|%. 010f|", 2.345);
	ft_printf("||");
	ft_printf("|%-5+.3d|", 100);
	ft_printf("||\n");
	ft_printf("|%5.6-rp|");
	ft_printf("||\n");
	ft_printf("|%-4c|\n", 'a');
	ft_printf("|Hallo een var:\t%-0.4dzzz%#%|", 10);
	ft_printf("|\n");
}

int main(int argc, const char *argv[])
{

#ifdef HOPEFULLY_NOT_DEFINED

	printf("||");
	printf("|%3 hallo|", 1);
	printf("|%19 -.4f|", 1.0);
	printf("|%2+0%|");
	printf("|%2 2%|");
	printf("|%. 010f|", 2.345);
	printf("||");
	printf("|%-5+.3d|", 100);
	printf("||\n");
	printf("|%5.6-rp|");
	printf("||\n");
	printf("|%-4c|\n", 'a');
	ft_printf("|Hallo een var:\t%-0.4dzzz%#%|", 10);
	printf("|\n");

	printf("|%010.2f|\n", 100.2345678);
	printf("|%-10.2f|\n", 100.2345678);
	printf("|% 10.2f|\n", 100.2345678);
	printf("|%+010.2f|\n", 100.2345678);
	printf("|%+-10.2f|\n", 100.2345678);
	printf("|%+10.2f|\n", 100.2345678);
	printf("|\n");
	printf("|%010.2f|\n", -100.2345678);
	printf("|%-10.2f|\n", -100.2345678);
	printf("|% 10.2f|\n", -100.2345678);
	printf("|%+010.2f|\n", -100.2345678);
	printf("|%+-10.2f|\n", -100.2345678);
	printf("|%+10.2f|\n", -100.2345678);
	printf("|\n");

	printf("|%10.4d|\n", 100);
	printf("|%10.4d|\n", -100);
	printf("|%+10.4d|\n", 100);
	printf("|%+10.4d|\n", -100);
	printf("|\n");
	printf("|%8.4d|\n", 100);
	printf("|%8.4d|\n", -100);
	printf("|%+8.4d|\n", 100);
	printf("|% 8.4d|\n", 100);
	printf("|% 8.4d|\n", -100);
	printf("|%+-8.2d|\n", 100);
	printf("|%+-8.2d|\n", -100);
	printf("|%- 8.2d|\n", 100);
	printf("|%- 8.2d|\n", -100);
	printf("|\n");
	printf("|%08.4d|\n", 100);
	printf("|%08.4d|\n", -100);
	printf("|%0+8.4d|\n", 100);
	printf("|%0 8.4d|\n", 100);
	printf("|%0 8.4d|\n", -100);
	printf("|%0+-8.2d|\n", 100);
	printf("|%0+-8.2d|\n", -100);
	printf("|%0- 8.2d|\n", 100);
	printf("|%0- 8.2d|\n", -100);
	printf("|%6x|\n", 11);
	int a;
	int b;
	a = 0b00000000000000000000000010001000;
	b = 0b11111111111111111111111110001000;
	printf("|Hallo dit is een string en die maak ik omdat het kan %r|\n");
	ft_printf("|Hallo dit is een string en die maak ik omdat het kan %r|\n");
	printf("|%5%|\n");
	printf("|%5 10%|\n");
	printf("|%.5d|\n", 10);
	printf("|%.5 0 10d|\n", 10);
	ft_printf("|%.5 0 10d|\n", 10);
	printf("%hhx\n", -10);
	ft_printf("%hhx\n", -10);
	ft_printf("%05o", 43);
	printf("=== Decimal Numbers ===\n");
	printf("|%-10d|\n", 10);
	fflush(stdout);
	ft_printf("|%-10d|\n""\n", 10);
	printf("|%+10d|\n", 10);
	fflush(stdout);
	ft_printf("|%+10d|\n""\n", 10);
	printf("|%0 10d|\n", 10);
	fflush(stdout);
	ft_printf("|%0 10d|\n""\n", 10);
	printf("|%-10d|\n", -10);
	fflush(stdout);
	ft_printf("|%-10d|\n""\n", -10);
	printf("|%+10d|\n", -10);
	fflush(stdout);
	ft_printf("|%+10d|\n""\n", -10);
	printf("|%0 10d|\n", -10);
	fflush(stdout);
	ft_printf("|%0 10d|\n""\n", -10);
	printf("|%d|\n", -10);
	fflush(stdout);
	ft_printf("|%d|\n""\n", -10);
	printf("|%d|\n", 10);
	fflush(stdout);
	ft_printf("|%d|\n""\n", 10);
	printf("|%4d|\n", -1646);
	fflush(stdout);
	ft_printf("|%4d|\n""\n", -1646);
	printf("|%5d|\n", -1646);
	fflush(stdout);
	ft_printf("|%5d|\n""\n", -1646);
	printf("|%6d|\n", -1646);
	fflush(stdout);
	ft_printf("|%6d|\n""\n", -1646);
	printf("|%10d|\n", -1646);
	fflush(stdout);
	ft_printf("|%10d|\n""\n", -1646);
	printf("|%-10.7d|\n", -1646);
	fflush(stdout);
	ft_printf("|%-10.7d|\n""\n", -1646);
	printf("|%-10.7d|\n", -1646);
	fflush(stdout);
	ft_printf("|%-10.7d|\n""\n", -1646);
	printf("\n\n=== Octal Numbers ===\n");
	printf("|%-10o|\n", 10);
	fflush(stdout);
	ft_printf("|%-10o|\n""\n", 10);
	printf("|%+10o|\n", 10);
	fflush(stdout);
	ft_printf("|%+10o|\n""\n", 10);
	printf("|%0 10o|\n", 10);
	fflush(stdout);
	ft_printf("|%0 10o|\n""\n", 10);
	printf("|%-10o|\n", 10);
	fflush(stdout);
	ft_printf("|%-10o|\n""\n", 10);
	printf("|%+10o|\n", 10);
	fflush(stdout);
	ft_printf("|%+10o|\n""\n", 10);
	printf("|%0 10o|\n", 10);
	fflush(stdout);
	ft_printf("|%0 10o|\n""\n", 10);
	printf("|%o|\n", 10);
	fflush(stdout);
	ft_printf("|%o|\n""\n", 10);
	printf("|%o|\n", 10);
	fflush(stdout);
	ft_printf("|%o|\n""\n", 10);
	printf("|%4o|\n", 1646);
	fflush(stdout);
	ft_printf("|%4o|\n""\n", 1646);
	printf("|%5o|\n", 1646);
	fflush(stdout);
	ft_printf("|%5o|\n""\n", 1646);
	printf("|%6o|\n", 1646);
	fflush(stdout);
	ft_printf("|%6o|\n""\n", 1646);
	printf("|%10o|\n", 1646);
	fflush(stdout);
	ft_printf("|%10o|\n""\n", 1646);
	printf("|%-10.7o|\n", 1646);
	fflush(stdout);
	ft_printf("|%-10.7o|\n""\n", 1646);
	printf("|%-10.7o|\n", 1646);
	fflush(stdout);
	ft_printf("|%-10.7o|\n""\n", 1646);
	printf("|\n");
	ft_printf("|before%cafter|\n", ' ');
	printf("|%zu|\n", ft_log(16, 16));
	printf("|%d|\n", 100);
	ft_printf("|%10.40%|\n");
	printf("|%10.40%|\n");
	ft_printf("|%-10.40%|\n");
	printf("|%-10.40%|\n");
	printf("|Test: -%c- this|\n", 0);
	fflush(stdout);
	ft_printf("|Test: -%c- this|\n", 0);
	ft_printf("|%#05.6o|\n", 20);
	printf("|%#05.6o|\n", 20);
	printf("writen: %d\n", ft_printf("test\n", 0));

#endif

    // sleep(1);

//    for (int a = 0; a < 1000; a++)
//    {
//        run_code();
//    }

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

	return (0);
}

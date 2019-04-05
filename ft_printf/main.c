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

#include <stdio.h>
#include <math.h>
#include "ft_printf.h"
#include "libft.h"

int main(int argc, const char * argv[]) {

//	printf("||");
//////	printf("|%3 hallo|", 1);
//////	printf("|%19 -.4f|", 1.0);
//////	printf("|%2+0%|");
//////	printf("|%2 2%|");
//	printf("|%. 010f|", 2.345);
//////	printf("||");
//////	printf("|%-5+.3d|", 100);
//////	printf("||\n");
//	printf("|%5.6-rp|");
//	printf("||\n");
//	printf("|%-4c|\n", 'a');
//	ft_printf("|Hallo een var:\t%-0.4dzzz%#%|", 10);
//	printf("|\n");

//	printf("|%010.2f|\n", 100.2345678 );
//	printf("|%-10.2f|\n", 100.2345678 );
//	printf("|% 10.2f|\n", 100.2345678 );
//	printf("|%+010.2f|\n", 100.2345678 );
//	printf("|%+-10.2f|\n", 100.2345678 );
//	printf("|%+10.2f|\n", 100.2345678 );
//	printf("|\n");
//	printf("|%010.2f|\n", -100.2345678 );
//	printf("|%-10.2f|\n", -100.2345678 );
//	printf("|% 10.2f|\n", -100.2345678 );
//	printf("|%+010.2f|\n", -100.2345678 );
//	printf("|%+-10.2f|\n", -100.2345678 );
//	printf("|%+10.2f|\n", -100.2345678 );
//	printf("|\n");

//	printf("|%10.4d|\n", 100);
//	printf("|%10.4d|\n", -100);
//	printf("|%+10.4d|\n", 100);
//	printf("|%+10.4d|\n", -100);
//	printf("|\n");
//	printf("|%8.4d|\n", 100);
//	printf("|%8.4d|\n", -100);
//	printf("|%+8.4d|\n", 100);
//	printf("|% 8.4d|\n", 100);
//	printf("|% 8.4d|\n", -100);
//	printf("|%+-8.2d|\n", 100);
//	printf("|%+-8.2d|\n", -100);
//	printf("|%- 8.2d|\n", 100);
//	printf("|%- 8.2d|\n", -100);
//	printf("|\n");
//	printf("|%08.4d|\n", 100);
//	printf("|%08.4d|\n", -100);
//	printf("|%0+8.4d|\n", 100);
//	printf("|%0 8.4d|\n", 100);
//	printf("|%0 8.4d|\n", -100);
//	printf("|%0+-8.2d|\n", 100);
//	printf("|%0+-8.2d|\n", -100);
//	printf("|%0- 8.2d|\n", 100);
//	printf("|%0- 8.2d|\n", -100);
//	printf("|%6x|\n", 11);

//	int a, b;
//
//	a = 0b00000000000000000000000010001000;
//	b = 0b11111111111111111111111110001000;
//
//

	printf("=== Decimal Numbers ===");
	printf("\n|%-10d|\n", 10); fflush(stdout);
	ft_printf("|%-10d|\n", 10);
	printf("\n|%+10d|\n", 10); fflush(stdout);
	ft_printf("|%+10d|\n", 10);
	printf("\n|%0 10d|\n", 10); fflush(stdout);
	ft_printf("|%0 10d|\n", 10);
	printf("\n|%-10d|\n", -10); fflush(stdout);
	ft_printf("|%-10d|\n", -10);
	printf("\n|%+10d|\n", -10); fflush(stdout);
	ft_printf("|%+10d|\n", -10);
	printf("\n|%0 10d|\n", -10); fflush(stdout);
	ft_printf("|%0 10d|\n", -10);
	printf("\n|%d|\n", -10); fflush(stdout);
	ft_printf("|%d|\n", -10);
	printf("\n|%d|\n", 10); fflush(stdout);
	ft_printf("|%d|\n", 10);
	printf("\n|%4d|\n", -1646); fflush(stdout);
	ft_printf("|%4d|\n", -1646);
	printf("\n|%5d|\n", -1646); fflush(stdout);
	ft_printf("|%5d|\n", -1646);
	printf("\n|%6d|\n", -1646); fflush(stdout);
	ft_printf("|%6d|\n", -1646);
	printf("\n|%10d|\n", -1646); fflush(stdout);
	ft_printf("|%10d|\n", -1646);
	printf("\n|%-10.7d|\n", -1646); fflush(stdout);
	ft_printf("|%-10.7d|\n", -1646);
	printf("\n|%-10.7d|\n", -1646); fflush(stdout);
	ft_printf("|%-10.7d|\n", -1646);

	printf("\n\n=== Octal Numbers ===");
	printf("\n|%-10o|\n", 10); fflush(stdout);
	ft_printf("|%-10o|\n", 10);
	printf("\n|%+10o|\n", 10); fflush(stdout);
	ft_printf("|%+10o|\n", 10);
	printf("\n|%0 10o|\n", 10); fflush(stdout);
	ft_printf("|%0 10o|\n", 10);
	printf("\n|%-10o|\n", 10); fflush(stdout);
	ft_printf("|%-10o|\n", 10);
	printf("\n|%+10o|\n", 10); fflush(stdout);
	ft_printf("|%+10o|\n", 10);
	printf("\n|%0 10o|\n", 10); fflush(stdout);
	ft_printf("|%0 10o|\n", 10);
	printf("\n|%o|\n", 10); fflush(stdout);
	ft_printf("|%o|\n", 10);
	printf("\n|%o|\n", 10); fflush(stdout);
	ft_printf("|%o|\n", 10);
	printf("\n|%4o|\n", 1646); fflush(stdout);
	ft_printf("|%4o|\n", 1646);
	printf("\n|%5o|\n", 1646); fflush(stdout);
	ft_printf("|%5o|\n", 1646);
	printf("\n|%6o|\n", 1646); fflush(stdout);
	ft_printf("|%6o|\n", 1646);
	printf("\n|%10o|\n", 1646); fflush(stdout);
	ft_printf("|%10o|\n", 1646);
	printf("\n|%-10.7o|\n", 1646); fflush(stdout);
	ft_printf("|%-10.7o|\n", 1646);
	printf("\n|%-10.7o|\n", 1646); fflush(stdout);
	ft_printf("|%-10.7o|\n", 1646);

//
//	printf("|\n");

//	ft_printf("|before%cafter|\n", ' ');


//	printf("|%zu|\n", ft_log(16, 16));

//	printf("|%d|\n", 100);

	return 0;
}


int main2(void)
{
	ft_printf("|% d|\n", 42);
	printf("|% d|\n", 42);
	//	printf("{%lf}	{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	//	ft_printf("{%lf}	{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242);
	//	ft_printf("% 10.5d|\n", 4242);
	//	printf("% 10.5d|\n", 4242);
	//	printf("@moulitest: %5.x %5.0x|\n", 0, 0);
	//	ft_printf("@moulitest: %5.x %5.0x|\n", 0, 0);
	//	printf("@moulitest: %5x |\n", 0, 0);
	//	ft_printf("@moulitest: %5x |\n", 0, 0);
	//	printf("@moulitest: %.o %.0o|\n", 0, 0);
	//	ft_printf("@moulitest: %.o %.0o|\n", 0, 0);
	//	printf("% 10.5d|\n", 4242);
	//	ft_printf("% 10.5d", 4242);
	//	ft_printf("%f\n", NULL);
	//	printf("%f", NULL);
	//	ft_printf("%hU\n", 4294967296);
	//	printf("%hU", 4294967296);
	//	ft_printf ("%100.20f\n%+.0f\n% 2.3f\n", -3.1416, 3.1416, 3.1416);
	//	printf("%.100Lf\n", 23823483.4293432236493246326432497023740234l); fflush(stdout);
	//	ft_printf("%.100Lf\n", 23823483.4293432236493246326432497023740234l);
	
//		ft_printf("|% d|\n", -42);
//		printf("@moulitest: %cmore\n", 0); fflush(stdout);
//
//		printf("|% d|\n", -42); fflush(stdout);
//		ft_printf("@moulitest: %cmore\n", 0);
//
//		printf("% +d\n", 42); fflush(stdout);
//		ft_printf("% +d\n", 42);
//		printf("% +d\n", -42); fflush(stdout);
//		ft_printf("% +d\n", -42);
//		printf("%+ d\n", 42); fflush(stdout);
//		ft_printf("%+ d\n", 42);
//		printf("%+ d\n", -42); fflush(stdout);
//		ft_printf("%+ d\n", -42);
//		printf("%  +d\n", 42); fflush(stdout);
//		ft_printf("%  +d\n", 42);
//		printf("%  +d\n", -42); fflush(stdout);
//		ft_printf("%  +d\n", -42);
//		ft_printf("%+  d\n", 42);
//		ft_printf("%+  d\n", -42);
//		ft_printf("% ++d|\n", 42);
//		ft_printf("% ++d\n", -42);
//		ft_printf("%++ d\n", 42);
//		ft_printf("%++ d|\n", -42);
//		printf("% o|\n", -4294967295); fflush(stdout);
//		ft_printf("% o|\n", -4294967295);
//		printf("% u|\n", -4294967295); fflush(stdout);
//		ft_printf("% u|\n", -4294967295);
//		printf("% u|\n", 4294967295); fflush(stdout);
//		ft_printf("% u|\n", 4294967295);
//		printf("%5%|\n"); fflush(stdout);
//		ft_printf("%5%|\n");
//		printf("%-5%|\n"); fflush(stdout);
//		ft_printf("%-5%|\n");
//		printf("%-05d|\n", -42); fflush(stdout);
//		ft_printf("%-05d|\n", -42);
//		printf("%-05d|\n", 42); fflush(stdout);
//		ft_printf("%-05d|err\n", 42);
//		printf("% d|\n", -42); fflush(stdout);
//		ft_printf("% d|\n", -42);
//		printf("% +d|\n", 42); fflush(stdout);
//		ft_printf("% +d|\n", 42);
//		printf("% +d|\n", -42); fflush(stdout);
//		ft_printf("% +d|\n", -42);
//		ft_printf("%+ d|\n", 42);
//		ft_printf("%+ d|\n", -42);
//		ft_printf("%  +d|\n", 42);
//		ft_printf("%  +d|\n", -42);
//		ft_printf("%+  d|\n", 42);
//		ft_printf("%+  d|\n", -42);
//		ft_printf("% ++d|\n", 42);
//		ft_printf("% ++d|\n", -42);
//		ft_printf("%++ d|\n", 42);
//		ft_printf("%++ d|\n", -42);
//		printf("% 10.5d|\n", 4242); fflush(stdout);
//		ft_printf("% 10.5d|\n", 4242);
	
	//	ft_printf("%L.312f|\n", 127.3143L);
	//	printf("%L.312f|\n", 127.3143L); fflush(stdout);
	
	//	printf("%f\n", sqrt (-1)); fflush(stdout);
	//	ft_printf("%f\n", sqrt (-1));
	//	ft_printf("%48.2f|\n", 63.055);
	//	printf("%48.2f|\n", 63.055); fflush(stdout);
	//	ft_printf("%f|\n", 0.0);
	//	printf("%f|\n", 0.0); fflush(stdout);
	//	ft_printf("%#33.12f|\n", 0);
	//	printf("%#33.12f|\n", 0); fflush(stdout);
	//	ft_printf("%-#.20f|\n", 11.6);
	//	printf("%-#.20f|\n", 11.6); fflush(stdout);
	//	ft_printf("%33.12f|\n", -28.28);
	//	printf("%33.12f|\n", -28.28); fflush(stdout);
	//	ft_printf("ft:%-33.12f|\n", -28.28);
	//	printf("pf:%-33.12f|\n", -28.28); fflush(stdout);
	//	ft_printf("ft:%-33.12f|\n", 28.28);
	//	printf("pf:%-33.12f|\n", 28.28); fflush(stdout);
	//	ft_printf("%-#.10f|\n", 11.6);
	//	printf("%-#.10f|\n", 11.6); fflush(stdout);
	
	//	ft_printf("%31.2f|\n", 127.3143);
	//	printf("%31.2f|\n", 127.3143); fflush(stdout);
	//	ft_printf("%L.312f|\n", 127.3143L);
	//	printf("%L.312f|\n", 127.3143L); fflush(stdout);
	
	//	printf("%zu|\n", 184467.44073709551614); fflush(stdout);
	//	printf("%zu|\n", 18446744073709551614); fflush(stdout);
	//	ft_printf("%zu|\n", 18446744073709551614);
	
	//	printf("%020d\n", 22); fflush(stdout);
	//	ft_printf("%020d\n", 22);
	//	printf("%020.10d\n", 22); fflush(stdout);
	//	ft_printf("%020.10d\n", 22);
	//	printf("%100.20d|\n", 124141); fflush(stdout);
	//	ft_printf("%100.20d|\n", 124141);
	//	printf("%-100.20d|\n", 124141); fflush(stdout);
	//	ft_printf("%-100.20d|\n", 124141);
	//	printf("% -10.200d|\n", 124141); fflush(stdout);
	//	ft_printf("% -10.200d|\n", 124141);
	//	printf("%+-100.20d|\n", 124141); fflush(stdout);
	//	ft_printf("%+-100.20d|\n", 124141);
	//	printf("%+100.20d|\n", -124141); fflush(stdout);
	//	ft_printf("%+100.20d|\n", -124141);
	//	printf("%100.20d|\n", -124141); fflush(stdout);
	//	ft_printf("%100.20d|\n", -124141);
	//	printf("%100.20d|\n", 124141); fflush(stdout);
	//	ft_printf("%100.20d|\n", 124141);
	//	printf("%+100.20d|\n", 124141); fflush(stdout);
	//	ft_printf("%+100.20d|\n", 124141);
	//	printf("\n"); fflush(stdout);
	//	ft_printf("%X|\n", -42);
	//	printf("%X|\n", -42);
	//	ft_printf("%X\n", 4294967296);
	//	printf("%X\n", 4294967296);//	printf ("%100.20f\n%+.0f\n% 2.3f\n", -3.1416, 3.1416, 3.1416);
	//	printf("%#33.20x|\n", 37732); fflush(stdout);
	//	ft_printf("%#33.20x|\n", 37732);
	//	printf("%#20x|\n", 37732); fflush(stdout);
	//	ft_printf("%#20x|\n", 37732);
	//	printf("%#100.20x|\n", 37732); fflush(stdout);
	//	ft_printf("%#100.20x|\n", 37732);
	//	printf("%#0100x|\n", 37732); fflush(stdout);
	//	ft_printf("%#0100x|\n", 37732);
	//	printf("%#-100.20X|\n", 124141); fflush(stdout);
	//	ft_printf("%#-100.20X|\n", 124141);
	//	printf("%#-100.20x|\n", 124141); fflush(stdout);
	//	ft_printf("%#-100.20x|\n", 124141);
	//	printf("%#3.20x|\n", 0); fflush(stdout);
	//	ft_printf("%#.20x|\n", 0);
	//	printf("%#-20x|\n", 0); fflush(stdout);
	//	ft_printf("%#-20x|\n", 0);
	//	printf("%#100.20x|\n", 0); fflush(stdout);
	//	ft_printf("%#100.20x|\n", 0);
	//	printf("%#0100x|\n", 0); fflush(stdout);
	//	ft_printf("%#0100x|\n", 0);
	//	printf("%x\n", 505); fflush(stdout);
	//	ft_printf("%x\n", 505);
	//	printf("%X\n", 505); fflush(stdout);
	//	ft_printf("%X\n", 505);
	//	printf("\n"); fflush(stdout);
	
	//	printf("%.20u|\n", 37732); fflush(stdout);
	//	ft_printf("%.20u|\n", 37732);
	//	printf("%20u|\n", 37732); fflush(stdout);
	//	ft_printf("%20u|\n", 37732);
	//	printf("%100.20u|\n", 37732); fflush(stdout);
	//	ft_printf("%100.20u|\n", 37732);
	//	printf("%0100u|\n", 37732); fflush(stdout);
	//	ft_printf("%0100u|\n", 37732);
	//	printf("\n"); fflush(stdout);
	//	printf("%.20d|\n", 37732); fflush(stdout);
	//	ft_printf("%.20d|\n", 37732);
	//	printf("%20d|\n", 37732); fflush(stdout);
	//	ft_printf("%20d|\n", 37732);
	//	printf("%100.20d|\n", 37732); fflush(stdout);
	//	ft_printf("%100.20d|\n", 37732);
	//	printf("%0100d|\n", 37732); fflush(stdout);
	//	ft_printf("%0100d|\n", 37732);
	//	printf("\n"); fflush(stdout);
	//	printf("%5d|\n", -42); fflush(stdout);
	//	ft_printf("%5d|\n", -42);
	//	printf("%-5d|\n", -42); fflush(stdout);
	//	ft_printf("%-5d|\n", -42);
	//	printf("%05d|\n", -42); fflush(stdout);
	//	ft_printf("%05d|\n", -42);
	
	//	printf("%25.5d|\n", -42); fflush(stdout);
	//	ft_printf("%25.5d|\n", -42);
	//	printf("%-25.5d|\n", -42); fflush(stdout);
	//	ft_printf("%-25.5d|\n", -42);
	//	printf("\n"); fflush(stdout);
	//	printf("%.20d|\n", 0); fflush(stdout);
	//	ft_printf("%.20d|\n", 0);
	//	printf("%20d|\n", 0); fflush(stdout);
	//	ft_printf("%20d|\n", 0);
	//	printf("%100.20d|\n", 0); fflush(stdout);
	//	ft_printf("%100.20d|\n", 0);
	//	printf("%0100d|\n", 0); fflush(stdout);
	//	ft_printf("%0100d|\n", 0);
	//	printf("\n"); fflush(stdout);
	//	printf("\n"); fflush(stdout);
	//	printf("%#.20o|\n", 37732); fflush(stdout);
	//	ft_printf("%#.20o|\n", 37732);
	//	printf("%#20o|\n", 37732); fflush(stdout);
	//	ft_printf("%#20o|\n", 37732);
	//	printf("%#100.20o|\n", 37732); fflush(stdout);
	//	ft_printf("%#100.20o|\n", 37732);
	//	printf("%#0100o|\n", 37732); fflush(stdout);
	//	ft_printf("%#0100o|\n", 37732);
	//	printf("\n"); fflush(stdout);
	//	printf("%#.20o|\n", 0); fflush(stdout);
	//	ft_printf("%#.20o|\n", 0);
	//	printf("%#20o|\n", 0); fflush(stdout);
	//	ft_printf("%#20o|\n", 0);
	//	printf("%#100.20o|\n", 0); fflush(stdout);
	//	ft_printf("%#100.20o|\n", 0);
	//	printf("%#0100o|\n", 0); fflush(stdout);
	//	ft_printf("%#0100o|\n", 0);
	//	printf("\n"); fflush(stdout);
	
	//	printf("%5d|\n", 0); fflush(stdout);
	//	ft_printf("%5d|\n", 0);
	//	printf("%-5d|\n", 0); fflush(stdout);
	//	ft_printf("%-5d|\n", 0);
	//	printf("%05d|\n", 0); fflush(stdout);
	//	ft_printf("%05d|\n", 0);
	//	printf("%25.5d|\n", 0); fflush(stdout);
	//	ft_printf("%25.5d|\n", 0);
	//	printf("%-25.5d|\n", 0); fflush(stdout);
	//	ft_printf("%-25.5d|\n", 0);
	//	printf("%5.5d|\n", 0); fflush(stdout);
	//	ft_printf("%5.5d|\n", 0);
	//	printf("%x|\n", 0); fflush(stdout);
	//	ft_printf("%x|\n", 0);
	//	printf("%o|\n", 0); fflush(stdout);
	//	ft_printf("%o|\n", 0);
	//	printf("%u|\n", 0); fflush(stdout);
	//	ft_printf("%u|\n", 0);
	//	printf("%d|\n", 0); fflush(stdout);
	//	ft_printf("%d|\n", 0);
	//	printf("\n"); fflush(stdout);
	//	printf("%d\n", 42); fflush(stdout);
	//	ft_printf("%d\n", 42);
	//	printf("%d%d\n", 42, 41); fflush(stdout);
	//	ft_printf("%d%d\n", 42, 41);
	//	printf("%d%d%d\n", 42, 43, 44); fflush(stdout);
	//	ft_printf("%d%d%d\n", 42, 43, 44);
	//	printf("%ld\n", 2147483647); fflush(stdout);
	//	ft_printf("%ld\n", 2147483647);
	//	printf("%lld\n", 9223372036854775807); fflush(stdout);
	//	ft_printf("%lld\n", 9223372036854775807);
	//	printf("%20.15d\n", 54321); fflush(stdout);
	//	ft_printf("%20.15d\n", 54321);
	//	printf("%-10d\n", 3); fflush(stdout);
	//	ft_printf("%-10d\n", 3);
	//	printf("% d\n", 3); fflush(stdout);
	//	ft_printf("% d\n", 3);
	//	printf("%+d\n", 3); fflush(stdout);
	//	ft_printf("%+d\n", 3);
	//	printf("%010d\n", 1); fflush(stdout);
	//	ft_printf("%010d\n", 1);
	//	printf("%jd\n", 9223372036854775807); fflush(stdout);
	//	ft_printf("%jd\n", 9223372036854775807);
	//	printf("%zd\n", 4294967295); fflush(stdout);
	//	ft_printf("%zd\n", 4294967295);
	//	printf("%U\n", 4294967295); fflush(stdout);
	//	ft_printf("%U\n", 4294967295);
	//	printf("%u\n", 4294967295); fflush(stdout);
	//	ft_printf("%u\n", 4294967295);
	//	printf("%o\n", 40); fflush(stdout);
	//	ft_printf("%o\n", 40);
	//	printf("%x\n", 1000); fflush(stdout);
	//	ft_printf("%x\n", 1000);
	//	printf("%#X\n", 1000); fflush(stdout);
	//	ft_printf("%#X\n", 1000);
	//	printf("\n\n"); fflush(stdout);
	
	//	printf("HERE:	%hhd\n", 0); fflush(stdout);
	//	ft_printf("		%hhd\n", 0);
	//	printf("HERE:	%hd\n", 0); fflush(stdout);
	//	ft_printf("		%hd\n", 0);
	//	printf("HERE:	%hd\n", 33); fflush(stdout);
	//	ft_printf("		%hd\n", 33);
	//	printf("\n"); fflush(stdout);
	
	//	printf("%#.x|\n", 0); fflush(stdout);
	//	ft_printf("%#.x|\n", 0);
	//	printf("%#.o|\n", 0); fflush(stdout);
	//	ft_printf("%#.o|\n", 0);
	//	printf("%#.u|\n", 0); fflush(stdout);
	//	ft_printf("%#.u|\n", 0);
	//	printf("%#.d|\n", 0); fflush(stdout);
	//	ft_printf("%#.d|\n", 0);
	//	printf("\n"); fflush(stdout);
	
	//	printf("%.x|\n", 0); fflush(stdout);
	//	ft_printf("%.x|\n", 0);
	//	printf("%.o|\n", 0); fflush(stdout);
	//	ft_printf("%.o|\n", 0);
	//	printf("%.u|\n", 0); fflush(stdout);
	//	ft_printf("%.u|\n", 0);
	//	printf("%.d|\n", 0); fflush(stdout);
	//	ft_printf("%.d|\n", 0);
	//	printf("\n\n"); fflush(stdout);
	
	//	printf("%x|\n", 0); fflush(stdout);
	//	ft_printf("%x|\n", 0);
	//	printf("%o|\n", 0); fflush(stdout);
	//	ft_printf("%o|\n", 0);
	//	printf("%u|\n", 0); fflush(stdout);
	//	ft_printf("%u|\n", 0);
	//	printf("%d|\n", 0); fflush(stdout);
	//	ft_printf("%d|\n", 0);
	//	printf("\n\n"); fflush(stdout);
	
	//	printf("%p\n", &ft_printf); fflush(stdout);
	//	ft_printf("%p\n", &ft_printf);
	//	printf("%p\n", NULL); fflush(stdout);
	//	ft_printf("%p\n", NULL);
	//	printf("%.p\n", NULL); fflush(stdout);
	//	ft_printf("%.p\n", NULL);
	//	printf("%#.p\n", NULL); fflush(stdout);
	//	ft_printf("%#.p\n", NULL);
	//	printf("\n"); fflush(stdout);
	//	char	c[] = "sdfds";
	//	printf("%p\n", c); fflush(stdout);
	//	ft_printf("%p\n", c);
	//	printf("%p\n", "sddfgsd"); fflush(stdout);
	//	ft_printf("%p\n", "sddfgsd");
	//	printf("\n\n"); fflush(stdout);
	
	//	printf("%\n"); fflush(stdout);
	//	ft_printf("%\n");
	//	printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5); fflush(stdout);
	//	ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	//	printf("%hhd\n", 127 + 42); fflush(stdout);
	//	ft_printf("%hhd\n", 127 + 42);
	//	printf("{%03.2d}\n", 0); fflush(stdout);
	//	ft_printf("{%03.2d}\n", 0);
	//	printf("%o, %ho, %hho\n", -42, -42, -42); fflush(stdout);
	//	ft_printf("%o, %ho, %hho\n", -42, -42, -42);
	//	printf("%hhu, %hhu\n", 0, 127 + 42); fflush(stdout);
	//	ft_printf("%hhu, %hhu\n", 0, 127 + 42);
	//	printf("@moulitest: %5.o %5.0o|\n", 0, 0); fflush(stdout);
	//	ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);
	//	printf("%5.0o|\n", 0); fflush(stdout);
	//	ft_printf("%5.0o|\n", 0);
	//	printf("@moulitest: %5.d %5.0d|\n", 0, 0); fflush(stdout);
	//	ft_printf("@moulitest: %5.d %5.0d|\n", 0, 0);
	
	//	printf("%%\n"); fflush(stdout);
	//	ft_printf("%%\n");
	//	printf("%k\n"); fflush(stdout);
	//	ft_printf("%k\n");
	
	//	printf("%d\n", 44); fflush(stdout);
	//	ft_printf("%d\n", 44);
	//	printf("%f\n", 44.33); fflush(stdout);
	//	ft_printf("%f\n", 44.33);
	return (0);
}


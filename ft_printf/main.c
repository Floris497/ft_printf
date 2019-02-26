//
//  main.c
//  ft_printf
//
//  Created by Floris Fredrikze on 17/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "ft_printf.h"

int main(int argc, const char * argv[]) {

//	printf("|");
//////	printf("%3 hallo", 1);
//////	printf("%19 -.4f", 1.0);
//////	printf("%2+0%");
//////	printf("%2 2%");
//	printf("%. 010f", 2.345);
//////	printf("|");
//////	printf("%-5+.3d", 100);
//////	printf("|\n");
//	printf("%5.6-rp");
//	printf("|\n");
//	printf("|%-4c|\n", 'a');
//	ft_printf("Hallo een var:\t%-0.4dzzz%#%", 10);
//	printf("\n");

	printf("|%010.2f|\n", 100.2345678 );
	printf("|%-10.2f|\n", 100.2345678 );
	printf("|% 10.2f|\n", 100.2345678 );
	printf("|%+010.2f|\n", 100.2345678 );
	printf("|%+-10.2f|\n", 100.2345678 );
	printf("|%+10.2f|\n", 100.2345678 );
	printf("\n");
	printf("|%010.2f|\n", -100.2345678 );
	printf("|%-10.2f|\n", -100.2345678 );
	printf("|% 10.2f|\n", -100.2345678 );
	printf("|%+010.2f|\n", -100.2345678 );
	printf("|%+-10.2f|\n", -100.2345678 );
	printf("|%+10.2f|\n", -100.2345678 );
	printf("\n");
	printf("|%10.2d|\n", 100);
	printf("|%10.2d|\n", -100);
	printf("|%+10.2d|\n", 100);
	printf("|%+10.2d|\n", -100);
	printf("\n");
	ft_printf("|%hhllL#d|\n", 'a' );
	return 0;
}

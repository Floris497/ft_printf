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
#include "libft.h"

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

//	printf("|%010.2f|\n", 100.2345678 );
//	printf("|%-10.2f|\n", 100.2345678 );
//	printf("|% 10.2f|\n", 100.2345678 );
//	printf("|%+010.2f|\n", 100.2345678 );
//	printf("|%+-10.2f|\n", 100.2345678 );
//	printf("|%+10.2f|\n", 100.2345678 );
//	printf("\n");
//	printf("|%010.2f|\n", -100.2345678 );
//	printf("|%-10.2f|\n", -100.2345678 );
//	printf("|% 10.2f|\n", -100.2345678 );
//	printf("|%+010.2f|\n", -100.2345678 );
//	printf("|%+-10.2f|\n", -100.2345678 );
//	printf("|%+10.2f|\n", -100.2345678 );
//	printf("\n");

//	printf("|%10.4d|\n", 100);
//	printf("|%10.4d|\n", -100);
//	printf("|%+10.4d|\n", 100);
//	printf("|%+10.4d|\n", -100);
//	printf("\n");
//	printf("|%8.4d|\n", 100);
//	printf("|%8.4d|\n", -100);
//	printf("|%+8.4d|\n", 100);
//	printf("|% 8.4d|\n", 100);
//	printf("|% 8.4d|\n", -100);
//	printf("|%+-8.2d|\n", 100);
//	printf("|%+-8.2d|\n", -100);
//	printf("|%- 8.2d|\n", 100);
//	printf("|%- 8.2d|\n", -100);
//	printf("\n");
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

	int a, b;

	a = 0b00000000000000000000000010001000;
	b = 0b11111111111111111111111110001000;


	ft_printf("|%hhllL#d|\n", 100 );

//	printf("%zu\n", ft_log(16, 16));

//	printf("|%d|\n", 100);

	return 0;
}

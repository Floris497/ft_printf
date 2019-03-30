/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   db_print_struct.c                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:44 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:00 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#if DEBUG

#include "db_print_struct.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "ft_printf_print_object.h"

void	print_struct(const char *input, t_pf_obj *obj)
{
	const char *flags[6] = {
		"PF_HT_FLAG", "PF_ZR_FLAG", "PF_SP_FLAG",
		"PF_PL_FLAG", "PF_MN_FLAG", "PF_AP_FLAG"
		
	};
	const char *convs[21] = {
		"CONV_NS",
		"D_CONV", "I_CONV", "O_CONV", "U_CONV", "X_CONV", "XX_CONV",
		"N_CONV", "A_CONV", "XA_CONV", "E_CONV", "XE_CONV", "F_CONV",
		"XF_CONV", "G_CONV", "XG_CONV", "C_CONV", "S_CONV", "V_CONV",
		"P_CONV", "NOT_A_CONV"
	};
	const char *llen_mods[14] = {
		"LEN_MOD_NS",
		"HH_PF_LEN_MOD", "H_PF_LEN_MOD", "L_PF_LEN_MOD", "LL_PF_LEN_MOD",
		"XL_PF_LEN_MOD", "J_PF_LEN_MOD", "T_PF_LEN_MOD", "Z_PF_LEN_MOD",
		"V_PF_LEN_MOD", "VH_PF_LEN_MOD", "VL_PF_LEN_MOD", "VLL_PF_LEN_MOD ",
		"NO_LEN_MOD"
	};
	printf("\n");
	printf("==== STRUCT TO PRINT =====\n");
	printf("Format:\n\t|%.*s|\n", (int)(input - obj->part->start) + 1, obj->part->start);
	printf("Flags:\n");
	for (int i = 0; i < 6; i++)
	{
		if ((obj->part->flags & 0b1 << i) >= 1) {
			printf("\t%s\n", flags[i]);
		}
	}
	printf("Width:\n\t%d\n", obj->part->width);
	printf("Precis:\n\t%d\n", obj->part->prcs);

	printf("Conv:\n");
	if (obj->part->conv == NOT_A_CONV)
		printf("\t%s\n", convs[20]);
	else if (obj->part->conv == CONV_NS)
		printf("\t%s\n", convs[0]);
	else
	{
		for (int i = 0; i < 19; i++)
		{
			if ((obj->part->conv & 0b1 << i) >= 1) {
				printf("\t%s\n", convs[i + 1]);
			}
		}
	}

	printf("Length:\n");
	if (obj->part->len_mod & NO_LEN_MOD)
		printf("\t%s\n", llen_mods[13]);
	else if (obj->part->len_mod & LEN_MOD_NS)
		printf("\t%s\n", llen_mods[0]);
	else
	{
		for (int i = 0; i < 12; i++)
		{
			if ((obj->part->len_mod & 0b1 << i) >= 1) {
				printf("\t%s\n", llen_mods[i + 1]);
			}
		}
	}
	if (isprint((int)obj->part->value.u_ln_value))
		printf("Value:\n\t%c | <0x%02llX>\n",(int)obj->part->value.u_ln_value ,(unsigned long long)obj->part->value.u_ln_value);
	else
		printf("Value:\n\t<0x%llX>\n", (unsigned long long)obj->part->value.u_ln_value);
	printf("Printable:\n\t|");
	fflush(stdout);
	ft_print_object_clean(obj);
	printf("|\n");
	printf("======= END PRINT ========\n\n");
}

#endif

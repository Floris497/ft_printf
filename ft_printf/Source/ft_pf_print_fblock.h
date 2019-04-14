//
//  ft_pf_print_fblock.h
//  ft_printf
//
//  Created by Floris Fredrikze on 13/04/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PF_PRINT_FBLOCK_H
# define FT_PF_PRINT_FBLOCK_H

typedef enum e_blorder		t_blorder;

enum	e_blorder
{
	PF_BLOCK_ORDER_1, // {}
	PF_BLOCK_ORDER_2,
	PF_BLOCK_ORDER_3,
	PF_BLOCK_ORDER_4,
	PF_BLOCK_ORDER_5,
	PF_BLOCK_ORDER_6,
	PF_BLOCK_ORDER_7,
	PF_BLOCK_ORDER_8,
};

typedef struct s_fblock t_fblock;

struct s_fblock
{
	char	*prefix;
	char	*number;
	char	pad_chr;
	char	sign_chr;
	long	width;
	long	prcs;
};

#endif

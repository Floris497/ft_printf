//
//  ft_printf_types.h
//  ft_printf
//
//  Created by Floris Fredrikze on 17/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

#if DEBUG
	#define NYI "Not yet implemented"
#endif

#include <stddef.h>
#include <stdarg.h>

# pragma mark - enums

/*
** t_ft_return contains return codes
*/

typedef enum e_pf_ret		t_pf_ret;

enum	e_pf_ret
{
	PF_RET_SUCCESS			= 0,
	PF_RET_ERROR			= -1,
	PF_RET_FORMAT_ERROR		= -2,
	PF_RET_NO_STATE_SET		= -10,
};

/*
** t_pf_conversion contains the conversion types
*/

typedef enum e_pf_conv		t_pf_conv;

enum	e_pf_conv
{
	D_CONV		=  1,
	I_CONV		=  2,
	O_CONV		=  3,
	U_CONV		=  4,
	X_CONV		=  5,
	XX_CONV		=  6,
	N_CONV		=  7,
	A_CONV		=  8,
	XA_CONV		=  9,
	E_CONV		= 10,
	XE_CONV		= 11,
	F_CONV		= 12,
	XF_CONV		= 13,
	G_CONV		= 14,
	XG_CONV		= 15,
	C_CONV		= 16,
	S_CONV		= 17,
	V_CONV		= 18,
	P_CONV		= 19,
	NOT_A_CONV	= -1,
};

/*
** t_pf_LEN_MOD contains the len_modifier types
*/

typedef enum e_pf_len_mod		t_pf_len_mod;

enum	e_pf_len_mod
{
	HH_PF_LEN_MOD 		= 1,
	H_PF_LEN_MOD		= 2,
	L_PF_LEN_MOD		= 3,
	LL_PF_LEN_MOD		= 4,
	XL_PF_LEN_MOD		= 5,
	J_PF_LEN_MOD		= 6,
	T_PF_LEN_MOD		= 7,
	Z_PF_LEN_MOD		= 8,
	V_PF_LEN_MOD		= 9,
	VH_PF_LEN_MOD		= 10,
	VL_PF_LEN_MOD		= 11,
	VLL_PF_LEN_MOD 	= 12,
	NO_LEN_MOD			= -1,
};

/*
** t_pf_flag contains the flag types
*/

typedef enum e_pf_flag		t_pf_flag;

enum	e_pf_flag
{
	PF_HT_FLAG 		= 0b0000001,
	PF_ZR_FLAG		= 0b0000010,
	PF_SP_FLAG		= 0b0000100,
	PF_PL_FLAG		= 0b0001000,
	PF_MN_FLAG		= 0b0010000,
	PF_AP_FLAG		= 0b0100000,
};

# pragma mark - structs

typedef union u_pf_value		t_pf_value;

union u_pf_value
{
	signed int			s_it_value;
	signed char			s_ch_value;
	signed short		s_sh_value;
	signed long			s_ln_value;
	signed long long	s_ll_value;
	unsigned char		u_ch_value;
	unsigned short		u_sh_value;
	unsigned long		u_ln_value;
	unsigned long long	u_ll_value;
	double				s_db_value;
	long double			s_ld_value;
	char				*s_ch_ptr_value;
	void				*ptr;
};

typedef struct s_pf_part		t_pf_part;

struct	s_pf_part
{
	t_pf_flag				flags;
	int						width;
	int						prcs;
	t_pf_len_mod			len_mod;
	t_pf_conv				conv;
	t_pf_value				value;
#if DEBUG
	const char				*start;
#endif
};

typedef struct s_pf_obj t_pf_obj;

struct s_pf_obj
{
	t_pf_ret		(*print)(const char *);
	unsigned int	writen;
	t_pf_part		*part;
#if DEBUG
	t_pf_ret		(*print_db)(const char *);
	char			*error_message;
	const char		*format;
#endif
};

#endif

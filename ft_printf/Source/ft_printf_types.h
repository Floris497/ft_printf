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
	D_CONV		= 0b0000000000000000000001,
	I_CONV		= 0b0000000000000000000010,
	O_CONV		= 0b0000000000000000000100,
	U_CONV		= 0b0000000000000000001000,
	X_CONV		= 0b0000000000000000010000,
	XX_CONV		= 0b0000000000000000100000,
	N_CONV		= 0b0000000000000001000000,
	A_CONV		= 0b0000000000000010000000,
	XA_CONV		= 0b0000000000000100000000,
	E_CONV		= 0b0000000000001000000000,
	XE_CONV		= 0b0000000000010000000000,
	F_CONV		= 0b0000000000100000000000,
	XF_CONV		= 0b0000000001000000000000,
	G_CONV		= 0b0000000010000000000000,
	XG_CONV		= 0b0000000100000000000000,
	C_CONV		= 0b0000001000000000000000,
	S_CONV		= 0b0000010000000000000000,
	V_CONV		= 0b0000100000000000000000,
	P_CONV		= 0b0001000000000000000000,

	CONV_NS		= 0b0100000000000000000000,
	NOT_A_CONV	= 0b1000000000000000000000,
};

/*
** t_pf_LEN_MOD contains the len_modifier types
*/

typedef enum e_pf_len_mod		t_pf_len_mod;

enum	e_pf_len_mod
{
	HH_PF_LEN_MOD		= 0b0000000000000001,
	H_PF_LEN_MOD		= 0b0000000000000010,
	L_PF_LEN_MOD		= 0b0000000000000100,
	LL_PF_LEN_MOD		= 0b0000000000001000,
	XL_PF_LEN_MOD		= 0b0000000000010000,
	J_PF_LEN_MOD		= 0b0000000000100000,
	T_PF_LEN_MOD		= 0b0000000001000000,
	Z_PF_LEN_MOD		= 0b0000000010000000,
	V_PF_LEN_MOD		= 0b0000000100000000,
	VH_PF_LEN_MOD		= 0b0000001000000000,
	VL_PF_LEN_MOD		= 0b0000010000000000,
	VLL_PF_LEN_MOD		= 0b0000100000000000,
	LEN_MOD_NS			= 0b0100000000000000,
	NO_LEN_MOD			= 0b1000000000000000,
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
	size_t			chr_wrtn;
	t_pf_part		*part;
	va_list			*args;
	t_pf_ret		(*print)(const char *);
#if DEBUG
	t_pf_ret		(*print_clean)(const char *);
	char			*error_message;
	const char		*format;
#endif
};

#endif

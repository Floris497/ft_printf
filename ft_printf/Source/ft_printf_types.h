//
//  ft_printf_types.h
//  ft_printf
//
//  Created by Floris Fredrikze on 17/02/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# pragma mark - definitions

# define FLAG_CHARS "0987654321#-+' hljtzL."

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
};

/*
** t_pf_conversion contains the conversion types
*/

# define PF_CONVERSION "diouxXnaAeEfFgGcsv"

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
	NOT_A_CONV	= -1,
};

/*
** t_pf_modifier contains the modifier types
*/

# define PF_MODIFIERS "hh\0h\0l\0ll\0L\nj\0t\0z\0v\0vh\0vl\0vll\0\0"

typedef enum e_pf_mod		t_pf_mod;

enum	e_pf_mod
{
	HH_PF_MODIFIER 		= 1,
	H_PF_MODIFIER		= 2,
	L_PF_MODIFIER		= 3,
	LL_PF_MODIFIER		= 4,
	XL_PF_MODIFIER		= 5,
	J_PF_MODIFIER		= 6,
	T_PF_MODIFIER		= 7,
	Z_PF_MODIFIER		= 8,
	V_PF_MODIFIER		= 9,
	VH_PF_MODIFIER		= 10,
	VL_PF_MODIFIER		= 11,
	VLL_PF_MODIFIER 	= 12,
	NO_MODIFIER			= -1,
};

/*
** t_pf_flag contains the flag types
*/

typedef enum e_pf_flag		t_pf_flag;

enum	e_pf_flag
{
	HT_PF_FLAG 		= 0b0000001,
	ZR_PF_FLAG		= 0b0000010,
	SP_PF_FLAG		= 0b0000100,
	PL_PF_FLAG		= 0b0001000,
	MN_PF_FLAG		= 0b0010000,
	AP_PF_FLAG		= 0b0100000,
};

# pragma mark - structs

typedef struct s_pf_part		t_pf_part;

struct	s_pf_part
{
	unsigned long			flags;
	int						width;
	int						precision;
	t_pf_mod				mod;
	t_pf_conv				conv;
	union
	{
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
	
};

typedef struct s_pf_obj t_pf_obj;

struct s_pf_obj
{
	void		(*print)(void *str);
	t_pf_part	*part_list;
};

#endif

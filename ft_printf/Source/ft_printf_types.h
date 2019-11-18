/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_types.h                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# if DEBUG
#  define NYI "Not yet implemented"
# endif

# include <stddef.h>
# include <stdarg.h>
# include <string.h>

# pragma mark - enums

/*
** t_ft_return contains return codes
*/

typedef enum e_pf_ret		t_pf_ret;

enum	e_pf_ret
{
	PF_RET_SUCCESS = 0,
	PF_RET_HAS_MORE = 1,
	PF_RET_ERROR = -1,
	PF_RET_FORMAT_ERROR = -2,
	PF_RET_WRITE_ERROR = -3,
	PF_RET_NO_STATE_SET = -10,
};

/*
** t_pf_conversion contains the conversion types
*/

typedef enum e_pf_conv		t_pf_conv;
typedef enum e_pf_conv	t_pf_conv;

enum	e_pf_conv
{
	D_CONV = 1 << 21,
	I_CONV = 1 << 20,
	O_CONV = 1 << 19,
	U_CONV = 1 << 18,
	X_CONV = 1 << 17,
	XX_CONV = 1 << 16,
	N_CONV = 1 << 15,
	A_CONV = 1 << 14,
	XA_CONV = 1 << 13,
	E_CONV = 1 << 12,
	XE_CONV = 1 << 11,
	F_CONV = 1 << 10,
	XF_CONV = 1 << 9,
	G_CONV = 1 << 8,
	XG_CONV = 1 << 7,
	C_CONV = 1 << 6,
	S_CONV = 1 << 5,
	V_CONV = 1 << 4,
	P_CONV = 1 << 3,
	B_CONV = 1 << 2,
	CONV_NS = 1 << 1,
	NOT_A_CONV = 1 << 0,
};


/*
** t_pf_LEN_MOD contains the len_modifier types
*/

typedef enum e_pf_len_mod	t_pf_len_mod;

enum	e_pf_len_mod
{
	HH_PF_LEN_MOD = 1 << 16,
	H_PF_LEN_MOD = 1 << 15,
	L_PF_LEN_MOD = 1 << 14,
	LL_PF_LEN_MOD = 1 << 13,
	XL_PF_LEN_MOD = 1 << 12,
	J_PF_LEN_MOD = 1 << 11,
	T_PF_LEN_MOD = 1 << 10,
	Z_PF_LEN_MOD = 1 << 9,
	V_PF_LEN_MOD = 1 << 8,
	VH_PF_LEN_MOD = 1 << 7,
	VL_PF_LEN_MOD = 1 << 6,
	VLL_PF_LEN_MOD = 1 << 5,
	LEN_MOD_NS = 1 << 1,
	NO_LEN_MOD = 1 << 0,
};

/*
** t_pf_flag contains the flag types
*/

typedef enum e_pf_flag	t_pf_flag;

enum	e_pf_flag
{
	PF_HT_FLAG = 1 << 7,
	PF_ZR_FLAG = 1 << 6,
	PF_SP_FLAG = 1 << 5,
	PF_PL_FLAG = 1 << 4,
	PF_MN_FLAG = 1 << 3,
	PF_AP_FLAG = 1 << 2,
};

# pragma mark - structs

typedef union u_pf_value	t_pf_value;

union	u_pf_value
{
	signed int			s_it_value;
	signed char			s_ch_value;
	signed short		s_sh_value;
	signed long			s_ln_value;
	signed long long	s_ll_value;
	unsigned int		u_it_value;
	unsigned char		u_ch_value;
	unsigned short		u_sh_value;
	unsigned long		u_ln_value;
	unsigned long long	u_ll_value;
	float				s_fl_value;
	double				s_db_value;
	long double			s_ld_value;
	char				*s_ch_ptr_value;
	void				*ptr;
};

# define WIDTH_NS -1
# define PRECIS_NS -1

typedef struct s_pf_part	t_pf_part;

struct	s_pf_part
{
	t_pf_flag				flags;
	int						width;
	int						prcs;
	t_pf_len_mod			len_mod;
	t_pf_conv				conv;
	t_pf_value				value;
};

# define LEN_NS -1

typedef struct s_pf_obj		t_pf_obj;

struct	s_pf_obj
{
	const char 		*input;
	size_t			chr_wrtn;
	t_pf_part		*part;
	va_list			*args;
	t_pf_ret		(*print)(const char *, ssize_t, t_pf_obj *);
};

typedef enum e_pf_blk_order	t_pf_blk_order;

enum	e_pf_blk_order
{
	SNP,
	SPN,
	PSN,
};

typedef struct s_lenblock	t_lenblock;

struct	s_lenblock
{
	int				r_prsc;
	int				r_width;
	int				pad_len;
	int				total_len;
	t_pf_blk_order	order;
};

typedef	struct 		s_ld_parts
{
	unsigned long	m;
	unsigned long	sign_exp;
}					t_ld_parts;

typedef union		u_pf_f2u
{
	long double		f;
	t_ld_parts		ld;
}					t_pf_f2u;

# define LD_SIGN 0x8000;
# define LD_EXP 0x7FFF;
# define LD_INTEGER_PART 0x8000000000000000;
# define LD_FRACTION 0x7FFFFFFFFFFFFFFF;
# define LD_MANTISSA_BITS 64;
# define LD_EXP_BIAS 16383;

#endif

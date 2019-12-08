# **************************************************************************** #
#                                                                              #
#                                                       ::::::::: :::::::::    #
#    Makefile                                          :+:       :+:           #
#                                                     +:+       +:+            #
#    By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#        #
#                                                   +#+       +#+              #
#    Created: 2019/01/08 16:32:51 by ffredrik      #+#       #+#               #
#    Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###                #
#                                                                              #
# **************************************************************************** #
	
NAME = libftprintf

CC = clang
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

HEADERS = \
	FSM/pf_fsm.h \
	ft_printf.h \
	ft_printf_len_mod_h.h \
	ft_printf_len_mod_hh.h \
	ft_printf_len_mod_l.h \
	ft_printf_len_mod_ll.h \
	ft_printf_len_mod_xl.h \
	ft_printf_private.h \
	ft_printf_types.h \
	object_printing/extra/pf_print_nchar.h \
	object_printing/extra/pf_print_pad.h \
	object_printing/extra/print_num_full/pf_print_num_full.h \
	object_printing/ft_printf_print.h \
	object_printing/print_conv_str/float_aux/float_aux.h \
	object_printing/print_conv_str/pf_print_conv.h \
	part_completion/pf_choose_length_for_mod.h

INCLUDES = \
	-I ./ \
	-I ./libft/includes/ \
	-I ./FSM/ \
	-I ./object_printing/ \
	-I ./object_printing/extra/ \
	-I ./object_printing/extra/print_num_full/ \
	-I ./object_printing/print_conv_str \
	-I ./object_printing/print_conv_str/float_aux \
	-I ./part_completion/ \
	-I ./object_printing/float_aux \

SRCS = \
	FSM/pf_fsm_controller_state.c \
	FSM/pf_fsm_conv_state.c \
	FSM/pf_fsm_end_state.c \
	FSM/pf_fsm_error_state.c \
	FSM/pf_fsm_flags_state.c \
	FSM/pf_fsm_init_state.c \
	FSM/pf_fsm_lenght_state.c \
	FSM/pf_fsm_precis_state.c \
	FSM/pf_fsm_print_char_state.c \
	FSM/pf_fsm_print_empty_object_state.c \
	FSM/pf_fsm_print_object_state.c \
	FSM/pf_fsm_start_state.c \
	FSM/pf_fsm_width_state.c \
	ft_printf.c \
	ft_printf_len_mod_h.c \
	ft_printf_len_mod_hh.c \
	ft_printf_len_mod_l.c \
	ft_printf_len_mod_ll.c \
	ft_printf_len_mod_xl.c \
	object_printing/extra/pf_print_nchar.c \
	object_printing/extra/pf_print_pad.c \
	object_printing/extra/print_num_full/pf_print_num_full_d.c \
	object_printing/ft_printf_print_object.c \
	object_printing/ft_printf_print_part_b.c \
	object_printing/ft_printf_print_part_c.c \
	object_printing/ft_printf_print_part_d.c \
	object_printing/ft_printf_print_part_f.c \
	object_printing/ft_printf_print_part_i.c \
	object_printing/ft_printf_print_part_o.c \
	object_printing/ft_printf_print_part_p.c \
	object_printing/ft_printf_print_part_s.c \
	object_printing/ft_printf_print_part_u.c \
	object_printing/ft_printf_print_part_x.c \
	object_printing/print_conv_str/float_aux/float_aux.c \
	object_printing/print_conv_str/float_aux/float_lhs.c \
	object_printing/print_conv_str/float_aux/float_rhs.c \
	object_printing/print_conv_str/float_aux/ft_ftoa.c \
	object_printing/print_conv_str/pf_print_conv_c.c \
	object_printing/print_conv_str/pf_print_conv_d.c \
	object_printing/print_conv_str/pf_print_conv_f.c \
	object_printing/print_conv_str/pf_print_conv_o.c \
	object_printing/print_conv_str/pf_print_conv_p.c \
	object_printing/print_conv_str/pf_print_conv_s.c \
	object_printing/print_conv_str/pf_print_conv_x.c \
	part_completion/pf_choose_length_for_mod.c

OBJS = $(SRCS:.c=.o)

.PHONY: clean fclean

all: $(NAME).a

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)
	@echo CC: $<

$(NAME).a: libft/libft.a $(OBJS)
	@cp libft/libft.a $(NAME).a
	@echo CREATING: $(NAME).a
	@$(AR) $(ARFLAGS) $(NAME).a $(OBJS)

dylib: $(NAME).dylib

$(NAME).dylib: libft/libft.a $(OBJS)
	@echo CREATING: $(NAME).dylib
	clang -fPIC -dynamiclib -o $(NAME).dylib $(OBJS) -lft -L./libft/

libft/libft.a: libft
	@make -C libft

fclean: clean
	@make -C libft fclean
	@echo DELETING: $(NAME).a
	@rm -f $(NAME).a 
	@echo DELETING: $(NAME).dylib
	@rm -f $(NAME).dylib

clean:
	@make -C libft clean
	@echo DELETING: $(OBJS)
	@rm -f $(OBJS)

re: fclean $(NAME).a
	

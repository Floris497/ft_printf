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

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

HEADERS = \
	$(wildcard *.h) \
	$(wildcard FSM/*.h) \
	$(wildcard object_printing/*.h) \
	$(wildcard object_printing/extra/*.h) \
	$(wildcard object_printing/extra/print_num_full/*.h) \
	$(wildcard object_printing/print_conv_str/*.h) \
	$(wildcard part_completion/*.h) \
	
INCLUDES = \
	-I ./ \
	-I ./libft/includes/ \
	-I ./FSM/ \
	-I ./object_printing/ \
	-I ./object_printing/extra/ \
	-I ./object_printing/extra/print_num_full/ \
	-I ./object_printing/print_conv_str \
	-I ./part_completion/ \

SRCS = \
	$(wildcard *.c) \
	$(wildcard FSM/*.c) \
	$(wildcard object_printing/*.c) \
	$(wildcard object_printing/extra/*.c) \
	$(wildcard object_printing/extra/print_num_full/*.c) \
	$(wildcard object_printing/print_conv_str/*.c) \
	$(wildcard part_completion/*.c) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)
	@echo CC: $<

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@echo MAKING LIBRARY
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

fclean: clean
	make -C libft fclean
	@echo REMOVING LIBRARY
	@rm -f $(NAME)

clean:
	make -C libft clean
	@echo REMOVING OBJECT FILES
	@rm -f $(OBJS)

re: fclean $(NAME)

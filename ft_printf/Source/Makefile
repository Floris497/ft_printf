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

HEADERS = 
INCLUDES = ./ ./libft/includes/ ./FSM/ ./object\ printing/

SRCS = $(wildcard *.c) $(wildcard FSM/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c $< $(CFLAGS) -I libft/includes -I ./FSM -I ./ -I object_printing/ ./part_completion
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

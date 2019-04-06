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

HEADERS = libft/includes/libft.h

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c $< $(CFLAGS) -I libft/includes
	@echo CC: $<

$(NAME): $(OBJS)
	@echo MAKING LIBRARY
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

fclean: clean
	@echo REMOVING LIBRARY
	@rm -f $(NAME)

clean:
	@echo REMOVING OBJECT FILES
	@rm -f $(OBJS)

re: fclean $(NAME)

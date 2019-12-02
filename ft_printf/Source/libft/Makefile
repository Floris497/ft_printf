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

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

HEADERS = includes/libft.h

SRCS = \
	ft_strncat.c \
	ft_count_if.c \
	ft_memccmp.c \
	ft_strnstr.c \
	ft_lstdequeue.c \
	ft_dictnew.c \
	ft_max.c \
	ft_lstadd.c \
	ft_isdigit.c \
	ft_putstr_fd.c \
	ft_strrepl.c \
	ft_strequ.c \
	ft_memdup.c \
	ft_foreach.c \
	ft_sqrt_ceil.c \
	ft_lstnew.c \
	ft_log.c \
	ft_dictadd.c \
	ft_strlen.c \
	ft_memrchr.c \
	ft_memcmp.c \
	ft_putnbr.c \
	ft_strclr.c \
	ft_itoa_base.c \
	ft_strsplit.c \
	ft_putnbr_fd.c \
	ft_lstiter.c \
	ft_slow_memchr.c \
	ft_strchr.c \
	ft_lstappend.c \
	ft_striteri.c \
	ft_bzero.c \
	ft_strichr.c \
	ft_strjoin.c \
	ft_isascii.c \
	ft_memcpy.c \
	ft_strstr.c \
	ft_memalloc.c \
	ft_putendl.c \
	ft_memccpy.c \
	ft_strcat.c \
	ft_isprint.c \
	ft_range.c \
	ft_putendl_fd.c \
	ft_strdel.c \
	ft_lstmap.c \
	ft_strctrim.c \
	ft_strclen.c \
	ft_strnequ.c \
	ft_toupper.c \
	ft_dictget.c \
	ft_putchar.c \
	ft_strrchr.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_strmap.c \
	ft_putchar_fd.c \
	ft_memset.c \
	ft_lstdel.c \
	ft_strncmp.c \
	ft_strcpy.c \
	ft_strllen.c \
	ft_lstunlink.c \
	ft_strupper.c \
	ft_dictfree.c \
	ft_min.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_memdel.c \
	ft_range_step.c \
	ft_strndup.c \
	ft_memmove.c \
	ft_islower.c \
	ft_strnew.c \
	ft_isupper.c \
	ft_putstr.c \
	ft_strlcat.c \
	ft_strlower.c \
	ft_dictremove.c \
	ft_strdup.c \
	ft_atoi.c \
	ft_memichr.c \
	ft_isalnum.c \
	ft_sqrt_floor.c \
	ft_lstdelone.c \
	ft_itoa.c \
	ft_striter.c \
	ft_lstfreeone.c \
	ft_memrcpy.c \
	ft_isspace.c \
	ft_strsub.c \
	ft_strncpy.c \
	ft_tolower.c \
	ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c $< $(CFLAGS) -I includes/
	@echo CC: $<

$(NAME): $(OBJS)
	@echo CREATING: $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

fclean: clean
	@echo DELETING: $(NAME)
	@rm -f $(NAME)

clean:
	@echo DELETING: $(OBJS)
	@rm -f $(OBJS)

re: fclean $(NAME)

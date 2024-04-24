# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:40:23 by lde-taey          #+#    #+#              #
#    Updated: 2024/04/19 12:21:42 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRCS = push_swap.c \
	checks.c \
	cleanup_stack.c \
	create_stack.c \
	error.c \
	ft_atoi_new.c \
	handle_stack.c \
	operations_1.c \
	operations_2.c \
	operations_3.c \
	process_stack.c \
	sort_3.c \
	sort_bigstack.c \
	sort_calculs_atob.c \
	sort_calculs_btoa.c \
	sort_execs.c \
	utils_1.c \
	utils_2.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

all : $(NAME)

.PHONY : all clean fclean re

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
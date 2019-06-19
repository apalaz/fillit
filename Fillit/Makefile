# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apalaz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 16:34:10 by apalaz            #+#    #+#              #
#    Updated: 2019/02/15 17:52:39 by apalaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/main.c srcs/ft_check_file.c srcs/ft_create_board.c			\
	   srcs/ft_resolve_tetri.c srcs/ft_valid.c srcs/ft_valid_tetri.c	\

OBJS = main.o ft_check_file.o ft_create_board.o ft_resolve_tetri.o		\
	   ft_valid.o ft_valid_tetri.o										\

HEADER = fillit.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

all: $(NAME)

$(NAME):
	@make re -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS) -I $(LIBFT) -I ./includes
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(LIBFT) -L$(LIBFT) -lft

clean:
	@make clean -C $(LIBFT)
	/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

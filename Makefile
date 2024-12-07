# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/03 14:52:50 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
HEAD_DIR = includes/
LIBFT_DIR = libft/

LIBFT_NAME = libft.a

all : $(NAME)

$(NAME) : 

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean :
	$(MAKE) $@ -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean : clean
	$(MAKE) $@ -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

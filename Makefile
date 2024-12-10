# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/10 02:12:54 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
HEAD_DIR = includes/
LIBFT_DIR = libft/

LIBFT_NAME = libft.a

SRCS = push_swap.c \
	  utils.c \
	  commands.c \
	  commands2.c

FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -I $(HEAD_DIR) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME) 

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR) -g

clean :
	$(MAKE) $@ -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean : clean
	$(MAKE) $@ -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

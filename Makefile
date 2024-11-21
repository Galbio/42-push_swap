# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2024/11/21 16:55:53 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
SRCS_DIR = srcs/
HEAD_DIR = includes/

SRCS = main.c \
	   ft_instructions.c \
	   ft_instructions2.c \
	   stack_utils.c \
	   utils.c \
	   sort_b_utils.c


FILES = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(FILES:.c=.o)

NAME = push_swap
LIBFT_NAME = $(addprefix $(LIBFT_DIR), libft.a)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling libft..."
	$(MAKE) bonus -C $(LIBFT_DIR)
	@echo "\nDone compiling!"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(HEAD_DIR) $(LIBFT_NAME) -g

libft : $(OBJS_LIBFT)
	ar -rcs $(LIBFT_NAME) $(OBJS_LIBFT)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR) -g

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

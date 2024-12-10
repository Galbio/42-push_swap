# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/10 02:45:02 by gakarbou         ###   ########.fr        #
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
	@echo "\033[0;34mCompiling libft..."
	@make bonus -C $(LIBFT_DIR) > /dev/null
	@echo "Done compiling libft!\n\033[0;0m"
	$(CC) $(FLAGS) $(OBJS) -I $(HEAD_DIR) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME) 
	@echo "\033[0;32mProgram compiled !!\033[0;0m"

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean :
	@echo "\033[0;31mRemoving libft objects..."
	@$(MAKE) $@ -C $(LIBFT_DIR) > /dev/null
	@echo "Finished removing libft objects!\033[0;0m"
	rm -f $(OBJS)

fclean : clean
	@echo "\033[0;31mRemoving libft.a..."
	@$(MAKE) $@ -C $(LIBFT_DIR) > /dev/null
	@echo "Done removing libft.a!\033[0;0m"
	rm -f $(NAME)

re : fclean all

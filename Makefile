# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/11 16:25:36 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -Wall -Wextra -Werror -D PRINT_DEBUG=1 -g

SRCS_DIR = srcs/
MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/
HEAD_DIR = includes/
LIBFT_DIR = libft/

LIBFT_NAME = libft.a

SRCS = utils.c \
	   parsing.c \
	   commands.c \
	   commands2.c

MANDATORY_SRCS = main.c \
				 get_op.c \
				 push_swap.c \
				 place_number.c

BONUS_SRCS = main.c

FILES = $(addprefix $(SRCS_DIR), $(SRCS))
MANDATORY_FILES = $(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
BONUS_FILES = $(addprefix $(BONUS_DIR), $(BONUS_SRCS))

OBJS = $(FILES:.c=.o)
MANDATORY_OBJS = $(MANDATORY_FILES:.c=.o)
BONUS_OBJS = $(BONUS_FILES:.c=.o)

debug : FLAGS = $(DEBUG_FLAGS)
debug : $(NAME) bonus
	

all : $(NAME)

$(NAME) : $(OBJS) $(MANDATORY_OBJS)
	@echo "\033[0;34mCompiling libft..."
	@make bonus -C $(LIBFT_DIR) > /dev/null
	@echo "Done compiling libft!\n\033[0;0m"
	$(CC) $(FLAGS) $(MANDATORY_OBJS) $(OBJS) -I $(HEAD_DIR) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)
	@echo "\033[0;32mProgram compiled !!\033[0;0m"

bonus : $(OBJS) $(BONUS_OBJS)
	@echo "\033[0;34mCompiling libft..."
	@make bonus -C $(LIBFT_DIR) > /dev/null
	@echo "Done compiling libft!\n\033[0;0m"
	$(CC) $(FLAGS) $(BONUS_OBJS) $(OBJS) -I $(HEAD_DIR) $(LIBFT_DIR)$(LIBFT_NAME) -o $(BONUS_NAME)
	@echo "\033[0;32mChecker created !!\033[0;0m"

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean :
	rm -f $(OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean : clean
	@echo "\033[0;31mRemoving libft.a and libft object..."
	@$(MAKE) $@ -C $(LIBFT_DIR) > /dev/null
	@echo "Done removing libft.a and all objects!\033[0;0m"
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 16:12:41 by gakarbou          #+#    #+#              #
#    Updated: 2024/12/09 23:22:49 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf/
GNL_DIR = gnl/
HEAD_DIR = includes/

NAME = libft.a

LIBFT_SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_abs.c \
		ft_max.c \
		ft_min.c

LIBFT_BONUS_SRCS = ft_lstnew_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstadd_back_bonus.c \
			 ft_lstsize_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstdelone_bonus.c \
			 ft_lstiter_bonus.c \
			 ft_lstclear_bonus.c \
			 ft_lstmap_bonus.c

GNL_SRCS = get_next_line.c \
		   get_next_line_utils.c

GNL_BONUS_SRCS = get_next_line_bonus.c \
				 get_next_line_utils_bonus.c

FT_PRINTF_SRCS = flags.c \
				 utils2.c \
				 writers.c \
				 writers2.c \
				 ft_printf.c


LIBFT_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))
LIBFT_BONUS_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_BONUS_SRCS))

GNL_FILES = $(addprefix $(GNL_DIR), $(GNL_SRCS))
GNL_BONUS_FILES = $(addprefix $(GNL_DIR), $(GNL_BONUS_SRCS))

FT_PRINTF_FILES = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_SRCS))

LIBFT_OBJS = $(LIBFT_FILES:.c=.o)
LIBFT_OBJS_BONUS = $(LIBFT_BONUS_FILES:.c=.o)

GNL_OBJS = $(GNL_FILES:.c=.o)
GNL_BONUS_OBJS = $(GNL_BONUS_FILES:.c=.o)

FT_PRINTF_OBJS = $(FT_PRINTF_FILES:.c=.o)


all : $(NAME)

$(NAME) : $(LIBFT_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	ar -rcs $(NAME) $(LIBFT_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

bonus : $(LIBFT_OBJS) $(LIBFT_OBJS_BONUS) $(GNL_BONUS_OBJS) $(FT_PRINTF_OBJS)
	ar -rcs $(NAME) $(LIBFT_OBJS) $(LIBFT_OBJS_BONUS) $(GNL_BONUS_OBJS) $(FT_PRINTF_OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR) -g

clean :
	rm -f $(LIBFT_OBJS) $(LIBFT_OBJS_BONUS) $(GNL_OBJS) $(GNL_BONUS_OBJS) $(FT_PRINTF_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

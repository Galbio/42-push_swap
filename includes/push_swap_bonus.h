/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:15:56 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/11 16:06:27 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int				size_a;
	int				size_b;
	t_list			*stack_a;
	t_list			*stack_b;
}	t_stacks;

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG 0
# endif

/*   Utils     */
int		gcv(t_list *node);
void	init_info(t_stacks *infos);
void	display_lst(t_stacks *info);
char	is_sorted(t_list *lst);

/*   Parsing   */
int		get_stacks_str(char *str, t_stacks **info);
int		get_stacks_argv(int size, char **argv, t_stacks **info);

/*   Commands  */
void	swap_a(t_stacks *stacks, char print);
void	swap_b(t_stacks *stacks, char print);
void	swap_swap(t_stacks *stacks, char print);
void	push_lst(t_stacks *lst, char id, char print);
void	rotate_a(t_stacks *lst, char print);
void	rotate_b(t_stacks *lst, char print);
void	rotate_rotate(t_stacks *lst, char print);
void	reverse_rotate_a(t_stacks *lst, char print);
void	reverse_rotate_b(t_stacks *lst, char print);
void	reverse_reverse_rotate(t_stacks *lst, char print);

/*   Other     */
int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);

#endif

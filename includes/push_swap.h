/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:15:56 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 17:29:26 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		compute_op(int order[2]);

/*   Parsing   */
int		get_stacks_str(char *str, t_stacks **info);
int		get_stacks_argv(int size, char **argv, t_stacks **info);

/*   Get nb op    */
int		get_op_number_tot(t_stacks *stacks, t_list *target);
int		get_target_number(int value, t_stacks *rot);
int		compute_min_op(int value, t_stacks *stacks);
void	get_final_order(int order[2], int i, int j, t_stacks *stacks);
void	ft_sort_nb(t_stacks *stacks);

/*   Place number */
char	min_case(t_stacks *stacks, t_list *target, int order[2]);
void	place_part_1(t_stacks *stacks, int cpy[2]);
char	place_number(t_stacks *stacks, int order[2], t_list *target);
void	sort_nb(t_stacks *stacks, t_list *target);

/*   Commands  */
void	swap_a(t_stacks *stacks, char print);
void	swap_b(t_stacks *stacks, char print);
void	push_lst(t_stacks *lst, char id);
void	rotate_a(t_stacks *lst, char print);
void	rotate_b(t_stacks *lst, char print);
void	rr(t_stacks *lst);
void	reverse_rotate_a(t_stacks *lst, char print);
void	reverse_rotate_b(t_stacks *lst, char print);
void	reverse_reverse_rotate(t_stacks *lst);

/*   Other     */
int		ft_printf(const char *format, ...);
char	push_swap(t_stacks *stacks);

#endif

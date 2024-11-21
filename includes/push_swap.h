/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:29:24 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/21 20:32:24 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
	int		og_size_a;
	int		og_size_b;
}	t_stack_info;

//Commands
void	swap_a(t_stack **stack, int size, char wr);
void	swap_b(t_stack **stack, int size, char wr);
void	swap_swap(t_stack_info *stacks);
void	push_a(t_stack_info *stacks);
void	push_b(t_stack_info *stacks);
void	rotate_lst(t_stack **lst, int size, char st_id);
void	rotate_rotate(t_stack_info *stacks);
void	reverse_rotate_lst(t_stack **lst, int size, char st_id);
void	reverse_rotate_rotate(t_stack_info *stacks);

t_stack	*ft_stack_last(t_stack *lst);
void	insert_ascending(t_stack_info *stacks, int value);
void	insert_max(t_stack_info *stacks);
int	ft_min(int a, int b);
void	display_stacks(t_stack_info *stacks);
int	stack_is_sorted(t_stack *stack);
int	stack_is_sorted_2(t_stack *stack);

#endif

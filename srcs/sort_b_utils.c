/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:34:10 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/22 17:49:00 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_ascending(t_stack_info *stacks, int value)
{
	while (!stack_is_sorted_2(stacks->stack_b))
		rotate_lst(&(stacks->stack_b), 1, 'b');
	if (ft_stack_last(stacks->stack_b)->value > value)
	{
		push_b(stacks);
		rotate_lst(&(stacks->stack_b), 1, 'b');
	}
	else if (value > stacks->stack_b->value)
		push_b(stacks);
	else
	{
		while (stacks->stack_b->value > value)
			rotate_lst(&(stacks->stack_b), stacks->size_b, 'b');
		push_b(stacks);
	}
}

void	insert_descending(t_stack_info *stacks, int value)
{
	while (!stack_is_sorted_2(stacks->stack_b))
		reverse_rotate_lst(&(stacks->stack_b), 1, 'b');
	if (ft_stack_last(stacks->stack_b)->value > value)
	{
		push_b(stacks);
		rotate_lst(&(stacks->stack_b), 1, 'b');
	}
	else if (value > stacks->stack_b->value)
		push_b(stacks);
	else
	{
		while (stacks->stack_b->value > value)
			rotate_lst(&(stacks->stack_b), stacks->size_b, 'b');
		push_b(stacks);
	}
}

int	stack_is_sorted_2(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:51:30 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/20 23:35:12 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack, int size, char wr)
{
	t_stack	*temp;

	if (wr)
		write(1, "sa\n", 3);
	if (size < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	*stack = temp;
}

void	swap_b(t_stack **stack, int size, char wr)
{
	t_stack	*temp;

	if (wr)
		write(1, "sb\n", 3);
	if (size < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	*stack = temp;
}

void	swap_swap(t_stack_info *stacks)
{
	write(1, "ss\n", 3);
	swap_a(&(stacks->stack_a), stacks->size_a, 0);
	swap_a(&(stacks->stack_b), stacks->size_b, 0);
}

void	push_a(t_stack_info *stacks)
{
	t_stack	*temp;

	write(1, "pa\n", 3);
	if (!stacks->size_a)
		return ;
	temp = stacks->stack_a->next;
	stacks->stack_a->next = stacks->stack_b;
	stacks->stack_b = stacks->stack_a;
	stacks->stack_a = temp;
	stacks->size_a -= 1;
	stacks->size_b += 1;
}

void	push_b(t_stack_info *stacks)
{
	t_stack	*temp;

	write(1, "pb\n", 3);
	if (!stacks->size_b)
		return ;
	temp = stacks->stack_b->next;
	stacks->stack_b->next = stacks->stack_a;
	stacks->stack_a = stacks->stack_b;
	stacks->stack_b = temp;
	stacks->size_b -= 1;
	stacks->size_a += 1;
}

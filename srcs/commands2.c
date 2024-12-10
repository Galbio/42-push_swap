/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:29:19 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 00:28:06 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *lst, char print)
{
	t_list	*sec_last;

	sec_last = lst->stack_a;
	while (sec_last->next->next)
		sec_last = sec_last->next;
	sec_last->next->next = lst->stack_a;
	lst->stack_a = sec_last->next;
	sec_last->next = NULL;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stacks *lst, char print)
{
	t_list	*sec_last;

	sec_last = lst->stack_b;
	while (sec_last->next->next)
		sec_last = sec_last->next;
	sec_last->next->next = lst->stack_b;
	lst->stack_b = sec_last->next;
	sec_last->next = NULL;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_reverse_rotate(t_stacks *lst)
{
	reverse_rotate_a(lst, 0);
	reverse_rotate_b(lst, 0);
	ft_putstr_fd("rrr\n", 1);
}

void	swap_swap(t_stacks *stacks)
{
	swap_a(stacks, 0);
	swap_b(stacks, 0);
	ft_putstr_fd("ss\n", 1);
}

void	push_lst(t_stacks *stacks, char id)
{
	t_list	*temp;

	if (id == 2)
	{
		temp = stacks->stack_a->next;
		stacks->stack_a->next = stacks->stack_b;
		stacks->stack_b = stacks->stack_a;
		stacks->stack_a = temp;
		stacks->size_b += 1;
		stacks->size_a -= 1;
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	temp = stacks->stack_b->next;
	stacks->stack_b->next = stacks->stack_a;
	stacks->stack_a = stacks->stack_b;
	stacks->stack_b = temp;
	stacks->size_b -= 1;
	stacks->size_a += 1;
	ft_putstr_fd("pa\n", 1);
}

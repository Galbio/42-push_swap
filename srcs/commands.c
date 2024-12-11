/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:32:53 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/11 16:14:21 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks, char print)
{
	t_list	*temp;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a->next;
		stacks->stack_a->next = temp->next;
		temp->next = stacks->stack_a;
		stacks->stack_a = temp;
	}
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stacks *stacks, char print)
{
	t_list	*temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b->next;
		stacks->stack_b->next = temp->next;
		temp->next = stacks->stack_b;
		stacks->stack_b = temp;
	}
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	rotate_a(t_stacks *lst, char print)
{
	t_list	*temp;

	if (lst->size_a)
	{
		temp = lst->stack_a;
		ft_lstlast(lst->stack_a)->next = temp;
		lst->stack_a = temp->next;
		temp->next = NULL;
	}
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stacks *lst, char print)
{
	t_list	*temp;

	if (lst->size_b)
	{
		temp = lst->stack_b;
		ft_lstlast(lst->stack_b)->next = temp;
		lst->stack_b = temp->next;
		temp->next = NULL;
	}
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_rotate(t_stacks *stacks, char print)
{
	if (stacks->size_a)
		rotate_a(stacks, 0);
	if (stacks->size_b)
		rotate_b(stacks, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

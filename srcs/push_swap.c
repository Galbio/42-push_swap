/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:48 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 17:27:10 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	ft_sort_three(t_stacks *stacks, int max, int min)
{
	t_list	*cur;

	cur = stacks->stack_a;
	if (max == gcv(cur))
	{
		if (min == gcv(cur->next))
			return (rotate_a(stacks, 1), 1);
		swap_a(stacks, 1);
		return (reverse_rotate_a(stacks, 1), 1);
	}
	else if (min != gcv(cur))
	{
		if (max == gcv(cur->next))
			return (reverse_rotate_a(stacks, 1), 1);
		return (swap_a(stacks, 1), 1);
	}
	swap_a(stacks, 1);
	return (rotate_a(stacks, 1), 1);
}

char	ft_sort_under_three(t_stacks *stacks)
{
	if (stacks->size_a == 1)
		return (0);
	else if (stacks->size_a == 2 && (gcv(stacks->stack_a)
			> gcv(stacks->stack_a->next)))
		return (swap_a(stacks, 1), 1);
	else
		return (ft_sort_three(stacks, ft_lstmax(stacks->stack_a, &gcv),
				ft_lstmin(stacks->stack_a, &gcv)), 1);
}

void	prepare_final_sorting(t_stacks *stacks, t_list *last_three[3])
{
	int		max;
	int		i;
	int		order;
	t_list	*temp;

	last_three[0] = stacks->stack_a;
	last_three[1] = stacks->stack_a->next;
	last_three[2] = stacks->stack_a->next->next;
	max = ft_lstmax(stacks->stack_b, &gcv);
	i = -1;
	temp = stacks->stack_b;
	while (gcv(temp) != max && ++i != -1)
		temp = temp->next;
	order = -1;
	if ((stacks->size_b / 2) >= i)
		order = 1;
	while (order > 0 && (gcv(stacks->stack_b) != max))
		rotate_b(stacks, 1);
	while (order < 0 && (gcv(stacks->stack_b) != max))
		reverse_rotate_b(stacks, 1);
}

void	ft_fill_stack_a(t_stacks *stacks, t_list *last_three[3])
{
	while (stacks->size_b && (gcv(stacks->stack_b)
			> gcv(last_three[2])))
		push_lst(stacks, 1);
	reverse_rotate_a(stacks, 1);
	while (stacks->size_b && (gcv(stacks->stack_b)
			> gcv(last_three[1])))
		push_lst(stacks, 1);
	reverse_rotate_a(stacks, 1);
	while (stacks->size_b && (gcv(stacks->stack_b)
			> gcv(last_three[0])))
		push_lst(stacks, 1);
	reverse_rotate_a(stacks, 1);
	while (stacks->size_b)
		push_lst(stacks, 1);
}

char	push_swap(t_stacks *stacks)
{
	t_list	*last_three[3];

	if (is_sorted(stacks->stack_a))
		return (1);
	else if (stacks->size_a <= 3)
		return (ft_sort_under_three(stacks), 0);
	push_lst(stacks, 2);
	if (stacks->size_a != 3)
		push_lst(stacks, 2);
	while (stacks->size_a != 3)
		ft_sort_nb(stacks);
	if (!is_sorted(stacks->stack_a))
		ft_sort_three(stacks, ft_lstmax(stacks->stack_a, &gcv),
			ft_lstmin(stacks->stack_a, &gcv));
	prepare_final_sorting(stacks, last_three);
	ft_fill_stack_a(stacks, last_three);
	return (0);
}

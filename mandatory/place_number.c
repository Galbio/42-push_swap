/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:11:24 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/11 15:37:21 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_part_1(t_stacks *stacks, int cpy[2])
{
	int	order[2];

	order[0] = cpy[0];
	order[1] = cpy[1];
	if (order[0] >= 0 || order[1] >= 0)
	{
		if (order[0] > 0 && order[1] > 0)
		{
			while (order[0] && order[1])
			{
				rotate_rotate(stacks, 1);
				order[0]--;
				order[1]--;
			}
		}
		if (order[0] > 0)
			while (order[0]-- > 0)
				rotate_a(stacks, 1);
		if (order[1] > 0)
			while (order[1]-- > 0)
				rotate_b(stacks, 1);
	}
}

char	min_case(t_stacks *stacks, t_list *target, int order[2])
{
	int	min;

	min = ft_lstmin(stacks->stack_b, &gcv);
	if (gcv(target) > min)
		return (0);
	min = ft_lstmax(stacks->stack_b, &gcv);
	while (gcv(stacks->stack_b) != min && (order[1] < 0))
		reverse_rotate_b(stacks, 1);
	while (gcv(stacks->stack_b) != min && (order[1] > 0))
		rotate_b(stacks, 1);
	while (gcv(stacks->stack_a) != gcv(target)
		&& (order[0] < 0))
		reverse_rotate_a(stacks, 1);
	while (gcv(stacks->stack_a) != gcv(target)
		&& (order[0] > 0))
		rotate_a(stacks, 1);
	return (1);
}

char	place_number(t_stacks *stacks, int order[2], t_list *target)
{
	if (min_case(stacks, target, order))
		return (push_lst(stacks, 2, 1), 1);
	place_part_1(stacks, order);
	if (order[0] < 0 || order[1] < 0)
	{
		if ((order[0] < 0) && (order[1] < 0))
		{
			while ((order[0] < 0) && (order[1] < 0))
			{
				reverse_reverse_rotate(stacks, 1);
				order[0]++;
				order[1]++;
			}
		}
		if (order[0] < 0)
			while (order[0]++ < 0)
				reverse_rotate_a(stacks, 1);
		if (order[1] < 0)
			while (order[1]++ < 0)
				reverse_rotate_b(stacks, 1);
	}
	push_lst(stacks, 2, 1);
	return (1);
}

void	sort_nb(t_stacks *stacks, t_list *target)
{
	int		i;
	int		j;
	int		order[2];
	t_list	*temp;

	i = 0;
	temp = stacks->stack_a;
	while (temp != target)
	{
		temp = temp->next;
		i++;
	}
	temp = stacks->stack_b;
	j = compute_min_op(gcv(target), stacks);
	get_final_order(order, i, j, stacks);
	place_number(stacks, order, target);
}

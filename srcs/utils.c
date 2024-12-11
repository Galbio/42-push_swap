/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:06:26 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/11 15:09:01 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_stacks *infos)
{
	infos->size_a = 0;
	infos->size_b = 0;
	infos->stack_a = NULL;
	infos->stack_b = NULL;
}

int	gcv(t_list *node)
{
	int	*cont;

	cont = (int *)node->content;
	return ((int)cont[0]);
}

void	display_lst(t_stacks *info)
{
	t_list	*cur;

	cur = info->stack_a;
	ft_putstr_fd("Stack A = ", 1);
	while (cur)
	{
		ft_printf("[%d] -> ", gcv(cur));
		cur = cur->next;
	}
	ft_putstr_fd("NULL\n\n", 1);
	cur = info->stack_b;
	ft_putstr_fd("Stack B = ", 1);
	while (cur)
	{
		ft_printf("[%d] -> ", gcv(cur));
		cur = cur->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

char	is_sorted(t_list *lst)
{
	int long	min;

	min = gcv(lst) - 1;
	while (lst)
	{
		if (gcv(lst) < min)
			return (0);
		min = gcv(lst);
		lst = lst->next;
	}
	return (1);
}

int	compute_op(int order[2])
{
	if (order[0] >= 0 && order[1] >= 0)
		return (1 + ft_max(order[0], order[1]));
	else if (order[0] < 0 && order[1] < 0)
		return (1 + ft_max(ft_abs(order[0]), ft_abs(order[1])));
	return (ft_abs(order[0]) + ft_abs(order[1]) + 1);
}

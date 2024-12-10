/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:13:51 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 17:23:17 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_number(int value, t_stacks *rot)
{
	int		count;
	int		target_nb;
	t_list	*lst;

	count = 0;
	target_nb = ft_lstmax(rot->stack_b, &gcv);
	while (gcv(rot->stack_b) != target_nb)
		rotate_b(rot, 0 * (count++));
	target_nb = 0;
	lst = rot->stack_b;
	while (lst)
	{
		if (gcv(lst) < value)
			break ;
		target_nb = gcv(lst);
		lst = lst->next;
	}
	target_nb = gcv(rot->stack_b);
	if (lst)
		target_nb = gcv(lst);
	while (count--)
		reverse_rotate_b(rot, 0);
	return (target_nb);
}

int	compute_min_op(int value, t_stacks *stacks)
{
	int		target_nb;
	int		res;
	t_list	*cur;

	target_nb = get_target_number(value, stacks);
	res = 0;
	cur = stacks->stack_b;
	while (gcv(cur) != target_nb)
	{
		res++;
		cur = cur->next;
	}
	return (res);
}

void	get_final_order(int order[2], int i, int j, t_stacks *stacks)
{
	int	tot1;
	int	tot2;

	tot1 = ft_max(i, j);
	order[0] = i;
	order[1] = j;
	tot2 = ft_max(stacks->size_a - i, stacks->size_b - j);
	if (tot1 > tot2)
		order[0] = -(stacks->size_a - i);
	if (tot1 > tot2)
		order[1] = -(stacks->size_b - j);
	if (tot2 < tot1)
		tot1 = tot2;
	tot2 = (i + (stacks->size_b - j));
	if (tot2 < tot1)
		order[0] = i;
	if (tot2 < tot1)
		order[1] = -(stacks->size_b - j);
	if (tot2 < tot1)
		tot1 = tot2;
	tot2 = (j + (stacks->size_a - i));
	if (tot2 < tot1)
		order[0] = -(stacks->size_a - i);
	if (tot2 < tot1)
		order[1] = j;
}

int	get_op_number_tot(t_stacks *stacks, t_list *target)
{
	int		i;
	int		j;
	int		order[2];
	t_list	*temp;

	i = -1;
	temp = stacks->stack_a;
	while ((++i > -1) && temp != target)
		temp = temp->next;
	temp = stacks->stack_b;
	j = compute_min_op(gcv(target), stacks);
	get_final_order(order, i, j, stacks);
	return (1 + compute_op(order));
}

void	ft_sort_nb(t_stacks *stacks)
{
	int		nb_op;
	int		true_lowest;
	t_list	*cur;
	t_list	*cheapest;

	nb_op = 0;
	true_lowest = 0;
	cur = stacks->stack_a;
	cheapest = cur;
	if (PRINT_DEBUG)
		ft_printf("Cheap = ");
	while (cur && nb_op != 1)
	{
		nb_op = get_op_number_tot(stacks, cur);
		if (PRINT_DEBUG)
			ft_printf("[%d|%d] - ", gcv(cur), nb_op);
		if (!true_lowest || (nb_op < true_lowest))
			cheapest = cur;
		if (!true_lowest || (nb_op < true_lowest))
			true_lowest = nb_op;
		cur = cur->next;
	}
	if (PRINT_DEBUG)
		ft_putchar_fd('\n', 1);
	sort_nb(stacks, cheapest);
}

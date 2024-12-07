/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:48 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/07 04:23:41 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_maxe(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	init_info(t_stacks *infos)
{
	infos->size_a = 0;
	infos->size_b = 0;
	infos->stack_a = NULL;
	infos->stack_b = NULL;
}

int	get_content_val(t_list *node)
{
	int	*cont;

	cont = (int *)node->content;
	return ((int)cont[0]);
}

char	check_doubles(t_list *lst)
{
	t_list	*cur;

	while (lst)
	{
		cur = lst->next;
		while (cur)
		{
			if (get_content_val(cur) == get_content_val(lst))
				return (1);
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (0);
}

char	ft_check_value_error(char **str, int *to_add)
{
	char		sign;
	long int	nb;

	sign = 1;
	nb = 0;
	if (**str == '-')
		sign = -sign;
	if (**str == '-')
		(*str)++;
	if (!ft_isdigit(**str))
		return (1);
	while (ft_isdigit(**str))
	{
		nb = nb * 10 + (*(*str)++ - '0');
		if (nb > (2147483648 - (sign > 0)))
			return (1);
	}
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
	to_add[0] = nb * sign;
	return (0);
}

int	get_stacks_str(char *str, t_stacks **info)
{
	int	temp;
	int	*to_add;

	if (!str[0])
		return (1);
	*info = malloc(sizeof(t_stacks));
	if (!(*info))
		return (1);
	init_info(*info);
	while (*str)
	{
		to_add = malloc(sizeof(int));
		if (!to_add)
			return (ft_lstclear(&(*info)->stack_a, free), free(*info), 1);
		if (ft_check_value_error(&str, to_add))
			return (free(to_add), ft_lstclear(&(*info)->stack_a, free),
				free(*info), 1);
		ft_lstadd_back(&(*info)->stack_a, ft_lstnew((void *)to_add));
		(*info)->size_a++;
	}
	if (check_doubles((*info)->stack_a))
		return (ft_lstclear(&(*info)->stack_a, free), free(*info), 1);
	return (0);
}

char	ft_check_value_error_argv(char *str, int *to_add)
{
	char		sign;
	long int	nb;

	nb = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (1);
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*(str++) - '0');
		if (nb > (2147483648 - (sign > 0)))
			return (1);
	}
	if (*str)
		return (1);
	to_add[0] = nb * sign;
	return (0);
}

int	get_stacks_argv(int size, char **argv, t_stacks **info)
{
	int	i;
	int	*to_add;

	i = -1;
	*info = malloc(sizeof(t_stacks));
	if (!(*info))
		return (1);
	init_info(*info);
	while (++i < size)
	{
		to_add = malloc(sizeof(int));
		if (!to_add)
			return (ft_lstclear(&(*info)->stack_a, free), free(*info), 1);
		if (ft_check_value_error_argv(argv[i], to_add))
			return (free(to_add), ft_lstclear(&(*info)->stack_a, free),
				free(*info), 1);
		ft_lstadd_back(&(*info)->stack_a, ft_lstnew((void *)to_add));
	}
	(*info)->size_a = size;
	if (check_doubles((*info)->stack_a))
		return (ft_lstclear(&(*info)->stack_a, free), free(*info), 1);
	return (0);
}

void	display_lst(t_stacks *info)
{
	t_list	*cur;

	write(1, "\n\n\n", 3);
	cur = info->stack_a;
	ft_putstr_fd("Stack A = ", 1);
	while (cur)
	{
		ft_printf("[%d] -> ", get_content_val(cur));
		cur = cur->next;
	}
	write(1, "\n\n", 2);
	cur = info->stack_b;
	ft_putstr_fd("Stack B = ", 1);
	while (cur)
	{
		ft_printf("[%d] -> ", get_content_val(cur));
		cur = cur->next;
	}
}

char	ft_sort_three(t_stacks *stacks, int max, int min)
{
	t_list	*cur;

	cur = stacks->stack_a;
	if (max == get_content_val(cur))
	{
		if (min == get_content_val(cur->next))
			return (rotate_a(stacks, 1), 1);
		return (swap_a(stacks, 1), reverse_rotate_a(stacks, 1), 1);
	}
	else if (min != get_content_val(cur))
	{
		if (max == get_content_val(cur->next))
			return (reverse_rotate_a(stacks, 1), 1);
		return (swap_a(stacks, 1), 1);
	}
	if (max == get_content_val(cur->next))
		return (swap_a(stacks, 1), rotate_a(stacks, 1), 1);
	return (0);
}

char	ft_sort_under_three(t_stacks *stacks)
{
	int		max;
	int		min;
	t_list	*cur;

	if (stacks->size_a == 1)
		return (0);
	else if (stacks->size_a == 2 && (get_content_val(stacks->stack_a) >
		get_content_val(stacks->stack_a->next)))
		return (swap_a(stacks, 1), 1);
	else
		return (ft_sort_three(stacks, get_max(stacks->stack_a),
			get_min(stacks->stack_a)), 1);
}

int	get_target_number(int value, t_stacks *rot)
{
	int		count;
	int		target_nb;
	t_list	*lst;

	count = 0;
	while (get_content_val(rot->stack_b) < get_content_val(rot->stack_b->next))
		rotate_b(rot, count++ * 0);
	target_nb = 0;
	lst = rot->stack_b;
	while (lst)
	{
		if (get_content_val(lst) < value)
			break ;
		target_nb = get_content_val(lst);
		lst = lst->next;
	}
	target_nb = get_content_val(rot->stack_b);
	if (lst)
		target_nb = get_content_val(lst);
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
	while (get_content_val(cur) != target_nb)
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

	tot1 = ft_maxe(i, j);
	order[0] = i;
	order[1] = j;
	tot2 = ft_maxe(stacks->size_a - i, stacks->size_b - j);
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

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
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
	j = compute_min_op(get_content_val(target), stacks);
	get_final_order(order, i, j, stacks);
	return (1 + ft_abs(order[0]) + ft_abs(order[1]));
}

void	place_part_1(t_stacks *stacks, int order[2])
{
	if (order[0] >= 0 || order[1] >= 0)
	{
		if (order[0] > 0 && order[1] > 0)
			while ((order[0]-- > 0) && (order[1]-- > 0))
				rr(stacks);
		if (order[0] > 0)
			while (order[0]-- > 0)
				rotate_a(stacks, 1);
		if (order[1] > 0)
			while (order[1]-- > 0)
				rotate_b(stacks, 1);
	}
}

void	place_number(t_stacks *stacks, int order[2])
{
	int	cpy[2];

	cpy[0] = order[0];
	cpy[1] = order[1];
	place_part_1(stacks, cpy);
	if (order[0] < 0 || order[1] < 0)
	{
		if (order[0] < 0 && order[1] < 0)
			while (order[0]++ && order[1]++)
				reverse_reverse_rotate(stacks);
		if (order[0] < 0)
			while (order[0]++ < 0)
				reverse_rotate_a(stacks, 1);
		if (order[1] < 0)
			while (order[1]++ < 0)
				reverse_rotate_b(stacks, 1);
	}
	push_lst(stacks, 2);
}

void	sort_nb(t_stacks *stacks, t_list *target)
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
	j = compute_min_op(get_content_val(target), stacks);
	get_final_order(order, i, j, stacks);
	place_number(stacks, order);
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
	while (cur)
	{
		nb_op = get_op_number_tot(stacks, cur);
		if (!true_lowest || (nb_op < true_lowest))
		{
			cheapest = cur;
			true_lowest = nb_op;
		}
		cur = cur->next;
	}
	sort_nb(stacks, cheapest);
}

void	ft_fill_stack_a(t_stacks *stacks)
{
	int		max;
	t_list	*cur;

	max = get_max(stacks->stack_b);
	while (get_content_val(stacks->stack_b) != max)
		rotate_b(stacks, 1);
	if (get_content_val(stacks->stack_b) > get_content_val(stacks->stack_a->next->next))
	{
		push_lst(stacks, 1);
		rotate_a(stacks, 1);
	}
	cur = stacks->stack_a;
	while (stacks->size_b)
	{

		push_lst(stacks, 1);
	}
}

char	push_swap(t_stacks *stacks)
{
	if (stacks->size_a <= 3)
		return (ft_sort_under_three(stacks), 0);
	push_lst(stacks, 2);
	if (stacks->size_a != 3)
		push_lst(stacks, 2);
	while (stacks->size_a != 3)
		ft_sort_nb(stacks);
	ft_sort_three(stacks, get_max(stacks->stack_a), get_min(stacks->stack_a));
	return (0);
	while (stacks->size_b)
		ft_fill_stack_a(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*info;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (get_stacks_str(argv[1], &info))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		if (get_stacks_argv(argc - 1, argv + 1, &info))
			return (ft_putstr_fd("Error\n", 2), 1);
	push_swap(info);
	display_lst(info);
	return (ft_lstclear(&(info->stack_a), free), free(info), 0);
}

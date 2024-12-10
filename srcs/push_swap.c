/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:48 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 02:19:29 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		swap_a(stacks, 1);
		return (reverse_rotate_a(stacks, 1), 1);
	}
	else if (min != get_content_val(cur))
	{
		if (max == get_content_val(cur->next))
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
	else if (stacks->size_a == 2 && (get_content_val(stacks->stack_a)
			> get_content_val(stacks->stack_a->next)))
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
	target_nb = get_max(rot->stack_b);
	while (get_content_val(rot->stack_b) != target_nb)
		rotate_b(rot, 0 * (count++));
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

int	compute_op(int order[2])
{
	if (order[0] >= 0 && order[1] >= 0)
		return (1 + ft_max(order[0], order[1]));
	else if (order[0] < 0 && order[1] < 0)
		return (1 + ft_max(ft_abs(order[0]), ft_abs(order[1])));
	return (ft_abs(order[0]) + ft_abs(order[1]) + 1);
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
	return (1 + compute_op(order));
}

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
				rr(stacks);
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

	min = get_min(stacks->stack_b);
	if (get_content_val(target) > min)
		return (0);
	min = get_max(stacks->stack_b);
	while (get_content_val(stacks->stack_b) != min && (order[1] < 0))
		reverse_rotate_b(stacks, 1);
	while (get_content_val(stacks->stack_b) != min && (order[1] > 0))
		rotate_b(stacks, 1);
	while (get_content_val(stacks->stack_a) != get_content_val(target)
		&& (order[0] < 0))
		reverse_rotate_a(stacks, 1);
	while (get_content_val(stacks->stack_a) != get_content_val(target)
		&& (order[0] > 0))
		rotate_a(stacks, 1);
	return (1);
}

char	place_number(t_stacks *stacks, int order[2], t_list *target)
{
	if (min_case(stacks, target, order))
		return (push_lst(stacks, 2), 1);
	place_part_1(stacks, order);
	if (order[0] < 0 || order[1] < 0)
	{
		if ((order[0] < 0) && (order[1] < 0))
		{
			while ((order[0] < 0) && (order[1] < 0))
			{
				reverse_reverse_rotate(stacks);
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
	push_lst(stacks, 2);
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
	j = compute_min_op(get_content_val(target), stacks);
	get_final_order(order, i, j, stacks);
	place_number(stacks, order, target);
}

void	ft_sort_nb(t_stacks *stacks)
{
	int		nb_op;
	int		i;
	int		true_lowest;
	t_list	*cur;
	t_list	*cheapest;

	nb_op = 0;
	i = 0;
	true_lowest = 0;
	cur = stacks->stack_a;
	cheapest = cur;
	//ft_printf("Cheap = ");
	while (cur && nb_op != 1)
	{
		nb_op = get_op_number_tot(stacks, cur);
		//ft_printf("[%d|%d] - ", get_content_val(cur), nb_op);
		if (!true_lowest || (nb_op < true_lowest))
		{
			cheapest = cur;
			true_lowest = nb_op;
		}
		cur = cur->next;
		i++;
	}
	//ft_putchar_fd('\n', 1);
	sort_nb(stacks, cheapest);
}

char	is_sorted(t_list *lst)
{
	int long	min;

	min = get_content_val(lst) - 1;
	while (lst)
	{
		if (get_content_val(lst) < min)
			return (0);
		min = get_content_val(lst);
		lst = lst->next;
	}
	return (1);
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
	max = get_max(stacks->stack_b);
	i = -1;
	temp = stacks->stack_b;
	while (get_content_val(temp) != max && ++i != -1)
		temp = temp->next;
	order = -1;
	if ((stacks->size_b / 2) >= i)
		order = 1;
	while (order > 0 && (get_content_val(stacks->stack_b) != max))
		rotate_b(stacks, 1);
	while (order < 0 && (get_content_val(stacks->stack_b) != max))
		reverse_rotate_b(stacks, 1);
}

void	ft_fill_stack_a(t_stacks *stacks, t_list *last_three[3])
{
	char	stack_a_index;

	stack_a_index = 3;
	while (stacks->size_b && (get_content_val(stacks->stack_b)
			> get_content_val(last_three[2])))
		push_lst(stacks, 1);
	reverse_rotate_a(stacks, 1);
	while (stacks->size_b && (get_content_val(stacks->stack_b)
			> get_content_val(last_three[1])))
		push_lst(stacks, 1);
	reverse_rotate_a(stacks, 1);
	while (stacks->size_b && (get_content_val(stacks->stack_b)
			> get_content_val(last_three[0])))
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
		ft_sort_three(stacks, get_max(stacks->stack_a), get_min(stacks->stack_a));
	prepare_final_sorting(stacks, last_three);
	ft_fill_stack_a(stacks, last_three);
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
//	display_lst(info);
	return (ft_lstclear(&(info->stack_a), free), free(info), 0);
}

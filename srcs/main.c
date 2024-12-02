/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:10:43 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/22 18:03:10 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	check_argv_errors(char *str, long int *limits)
{
	int		i;
	char	sign;

	if (!str[0])
		return (0);
	i = -1;
	sign = 1;
	while (str[++i])
	{
		if (str[i] == '-' && !i)
			sign = -1;
		else if (ft_isdigit(str[i]))
		{
			*limits = *limits * 10 + (str[i] - 48);
			if (*limits > (2147483648 - (sign > 0)))
				return (0);
		}
		else
			return (0);
	}
	*limits *= sign;
	return (1);
}

void	ft_stack_add_front(t_stack **lst, t_stack *new)
{
	if (lst)
		new->next = *lst;
	*lst = new;
}

t_stack	*ft_create_elem(int nb)
{
	t_stack	*dest;

	dest = malloc(sizeof(t_stack));
	if (!dest)
		return (NULL);
	dest->next = 0;
	dest->value = nb;
	return (dest);
}

char	check_doubles(t_stack *start)
{
	t_stack	*cur;

	while (start)
	{
		cur = start->next;
		while (cur)
		{
			if (cur->value == start->value)
				return (1);
			cur = cur->next;
		}
		start = start->next;
	}
	return (0);
}

t_stack_info	*create_stacks(int argc, char **argv)
{
	char			error;
	int				i;
	long int		limits;
	t_stack_info	*stacks;

	error = 0;
	stacks = malloc(sizeof(t_stack_info));
	if (!stacks)
		return (NULL);
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	i = argc;
	while (!error && --i > 0)
	{
		limits = 0;
		if (!check_argv_errors(argv[i], &limits))
			error = 1;
		if (!error)
			ft_stack_add_front(&(stacks->stack_a), ft_create_elem(limits));
	}
	if (error || check_doubles(stacks->stack_a))
		return (NULL);
	return (stacks);
}

void	display_stacks(t_stack_info *stacks)
{
	int		i;
	t_stack	*cur;

	i = -1;
	cur = stacks->stack_a;
	write(1, "Stack A : ", 10);
	while (++i < stacks->size_a)
	{
		if (i)
			write(1, " -> ", 4);
		write(1, "[", 1);
		ft_putnbr_fd(cur->value, 1);
		write(1, "]", 1);
		cur = cur->next;
	}
	cur = stacks->stack_b;
	i = write(1, "\nStack B : ", 11) * 0 + -1;
	while (++i < stacks->size_b)
	{
		if (i)
			write(1, " -> ", 4);
		write(1, "[", 1);
		ft_putnbr_fd(cur->value, 1);
		write(1, "]", 1);
		cur = cur->next;
	}
	write(1, "\n", 1);
}

void	sort_under_3(t_stack_info *stacks)
{
	if (stacks->size_a == 2)
		if (stacks->stack_a->value > stacks->stack_a->next->value)
			swap_a(&(stacks->stack_a), 2, 1);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_pairs(t_stack_info *stacks, int saw)
{
	int	to_do;

	to_do = 0;
	if ((stacks->size_a - saw >= 2) && stacks->size_a >= 2
			&& (stacks->stack_a->value < stacks->stack_a->next->value))
		to_do += 1;
	if (stacks->size_b == 2 && stacks->stack_b->value < stacks->stack_b->next->value)
		to_do += 2;
	if (to_do == 3)
		swap_swap(stacks);
	else if (to_do == 2)
		swap_b(&(stacks->stack_b), stacks->size_b, 1);
	else if (to_do == 1)
		swap_a(&(stacks->stack_a), stacks->size_a, 1);
}

int	get_reverse_order(t_stack_info *stacks, int stack_len)
{
	t_stack	*cur;
	int		*lst;
	int		i;
	int		count;

	lst = malloc(sizeof(int) * stack_len);
	if (!lst)
		return (stack_len + 1);
	cur = stacks->stack_b;
	i = -1;
	count = 0;
	while (++i < stack_len)
	{
		lst[i] = cur->value;
		cur = cur->next;
	}
	i = stack_len;
	while (--i >= 0 && stacks->stack_a->value < lst[i])
		count++;
	free(lst);
	return (count);
}

char	get_order(t_stack_info *stacks)
{
	t_stack	*cur;
	int		count;
	int		count2;

	if (stacks->stack_a->value > ft_stack_last(stacks->stack_b)->value)
		return (3);
	cur = stacks->stack_b;
	count = 0;
	count2 = 0;
	while (stacks->stack_a->value > cur->value)
	{
		cur = cur->next;
		count++;
	}
	if (count < 2)
		return (1);		
	count2 = get_reverse_order(stacks, stacks->size_b);
	if (count < count2)
		return (1);
	return (2);
}

void	ft_sort_into_b(t_stack_info *stacks, int size, int saw)
{
	char	order;
	int		i;
	int		og_size;

	order = get_order(stacks);
	og_size = stacks->size_a;
	i = -1;
	if (order == 1)
		while (++i < ft_min(size, (og_size - saw)))
			insert_ascending(stacks, stacks->stack_a->value);
	else
		while (++i < ft_min(size, (og_size - saw)))
			insert_descending(stacks, stacks->stack_a->value);
	while (!stack_is_sorted_2(stacks->stack_b))
		rotate_lst(&(stacks->stack_b), 1, 'b');
	while (stacks->size_b)
	{
		push_a(stacks);
		reverse_rotate_lst(&(stacks->stack_a), 2, 'a');
	}
}

int	push_swap(t_stack_info *stacks)
{
	int	size;
	int	saw;
	int	count;

	if (stacks->size_a < 3)
		return (sort_under_3(stacks), 0);
	size = 2;
	saw = 0;
	while ((stacks->size_a + stacks->size_b) > size)
	{
		if (stack_is_sorted(stacks->stack_a))
			return (1);
		count = -1;
		while (++count < ft_min(size, stacks->og_size_a - saw))
			push_b(stacks);
		if (size == 2)
			sort_pairs(stacks, saw);
		ft_sort_into_b(stacks, size, saw);
		saw += size * 2;
		if (saw >= stacks->size_a)
			size *= 2;
		if (saw >= (stacks->size_a + stacks->size_b))
			saw = 0;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_stack_info	*stacks;

	if (argc == 1)
		return (0);
	stacks = create_stacks(argc, argv);
	if (!stacks)
		return (0);
	stacks->og_size_a = stacks->size_a;
	stacks->og_size_b = stacks->size_b;
	push_swap(stacks);
	display_stacks(stacks);
	return (0);
}

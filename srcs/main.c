/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:10:43 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/20 23:36:38 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack_info	*stacks;

	if (argc == 1)
		return (0);
	stacks = create_stacks(argc, argv);
	if (!stacks)
		return (0);
	display_stacks(stacks);
	push_a(stacks);
	swap_swap(stacks);
	display_stacks(stacks);
	push_b(stacks);
	reverse_rotate_rotate(stacks);
	display_stacks(stacks);
	return (0);
}

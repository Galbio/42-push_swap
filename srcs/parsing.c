/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:00:09 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 17:03:04 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	check_doubles(t_list *lst)
{
	t_list	*cur;

	while (lst)
	{
		cur = lst->next;
		while (cur)
		{
			if (gcv(cur) == gcv(lst))
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

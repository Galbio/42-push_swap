/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:16:33 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/22 18:05:29 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_lst(t_stack **lst, int size, char st_id)
{
	t_stack	*temp;

	if (st_id)
	{
		write(1, "r", 1);
		write(1, &st_id, 1);
		write(1, "\n", 1);
	}
	if (!size)
		return ;
	temp = ft_stack_last(*lst);
	temp->next = *lst;
	temp = (*lst)->next;
	(*lst)->next = NULL;
	*lst = temp;
}

void	rotate_rotate(t_stack_info *stacks)
{
	write(1, "rr\n", 3);
	rotate_lst(&(stacks->stack_a), stacks->size_a, 0);
	rotate_lst(&(stacks->stack_b), stacks->size_b, 0);
}

void	reverse_rotate_lst(t_stack **lst, int size, char st_id)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (st_id)
	{
		write(1, "rr", 2);
		write(1, &st_id, 1);
		write(1, "\n", 1);
	}
	if (!size)
		return ;
	temp = ft_stack_last(*lst);
	temp->next = *lst;
	temp2 = *lst;
	*lst = temp;
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
}

void	reverse_rotate_rotate(t_stack_info *stacks)
{
	write(1, "rrr\n", 4);
	reverse_rotate_lst(&(stacks->stack_a), stacks->size_a, 0);
	reverse_rotate_lst(&(stacks->stack_b), stacks->size_b, 0);
}

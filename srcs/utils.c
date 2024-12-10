/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:15:01 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/07 01:47:40 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *lst)
{
	int	min;

	min = get_content_val(lst);
	lst = lst->next;
	while (lst)
	{
		if (get_content_val(lst) < min)
			min = get_content_val(lst);
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_list *lst)
{
	int	max;

	max = get_content_val(lst);
	lst = lst->next;
	while (lst)
	{
		if (get_content_val(lst) > max)
			max = get_content_val(lst);
		lst = lst->next;
	}
	return (max);
}

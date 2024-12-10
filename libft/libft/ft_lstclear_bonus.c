/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:22:16 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/06 14:39:14 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->content)
			del(cur->content);
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:26:44 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 17:27:08 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (PRINT_DEBUG)
		display_lst(info);
	return (ft_lstclear(&(info->stack_a), free), free(info), 0);
}

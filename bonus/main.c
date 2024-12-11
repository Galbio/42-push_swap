/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:12:31 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/11 17:20:42 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	execute_cmd_2(char *line, t_stacks *stacks)
{
	if (!ft_strncmp(line, "rra", 4))
		return (reverse_rotate_a(stacks, 0), 0);
	else if (!ft_strncmp(line, "rrb", 4))
		return (reverse_rotate_b(stacks, 0), 0);
	else if (!ft_strncmp(line, "rrr", 4))
		return (reverse_reverse_rotate(stacks, 0), 0);
	else if (!ft_strncmp(line, "display", 8) && PRINT_DEBUG)
		return (display_lst(stacks), 0);
	return (1);
}

char	execute_cmd(char *line, t_stacks *stacks)
{
	if (!ft_strncmp(line, "sa", 3))
		return (swap_a(stacks, 0), 0);
	else if (!ft_strncmp(line, "sb", 3))
		return (swap_b(stacks, 0), 0);
	else if (!ft_strncmp(line, "ss", 3))
		return (swap_swap(stacks, 0), 0);
	else if (!ft_strncmp(line, "pa", 3))
		return (push_lst(stacks, 1, 0), 0);
	else if (!ft_strncmp(line, "pb", 3))
		return (push_lst(stacks, 2, 0), 0);
	else if (!ft_strncmp(line, "ra", 3))
		return (rotate_a(stacks, 0), 0);
	else if (!ft_strncmp(line, "rb", 3))
		return (rotate_b(stacks, 0), 0);
	else if (!ft_strncmp(line, "rr", 3))
		return (rotate_rotate(stacks, 0), 0);
	else
		return (execute_cmd_2(line, stacks));
}

char	read_instructions(t_stacks *stacks)
{
	char	*line;
	int		i;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		i = -1;
		while (line[++i])
			if (line[i] == '\n')
				line[i] = 0;
		if (execute_cmd(line, stacks))
			return (free(line), 1);
		free(line);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (get_stacks_str(argv[1], &stacks))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		if (get_stacks_argv(argc - 1, argv + 1, &stacks))
			return (ft_putstr_fd("Error\n", 2), 1);
	if (read_instructions(stacks))
	{
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	if (PRINT_DEBUG)
		display_lst(stacks);
	if (is_sorted(stacks->stack_a) && !stacks->size_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (ft_lstclear(&(stacks->stack_a), free), free(stacks), 0);
}

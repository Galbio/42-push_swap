/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:15:56 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/07 02:50:43 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int				size_a;
	int				size_b;
	t_list			*stack_a;
	t_list			*stack_b;
}	t_stacks;

int	ft_printf(const char *format, ...);

int	get_max(t_list *lst);
int	get_min(t_list *lst);
int	get_content_val(t_list *node);

/*   Commands  */
void	swap_a(t_stacks *stacks, char print);
void	swap_b(t_stacks *stacks, char print);
void	push_lst(t_stacks *lst, char id);
void	rotate_a(t_stacks *lst, char print);
void	rotate_b(t_stacks *lst, char print);
void	rr(t_stacks *lst);
void	reverse_rotate_a(t_stacks *lst, char print);
void	reverse_rotate_b(t_stacks *lst, char print);
void	reverse_reverse_rotate(t_stacks *lst);

#endif

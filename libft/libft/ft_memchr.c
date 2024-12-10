/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:11 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 16:19:38 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = -1;
	str = (unsigned char *)s;
	while (++i < len)
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
	return (NULL);
}

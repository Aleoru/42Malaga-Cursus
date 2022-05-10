/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:44:23 by aoropeza          #+#    #+#             */
/*   Updated: 2022/05/10 18:13:12 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t nb)
{
	const char	*mem_str;
	size_t		index;

	mem_str = (const char *)str;
	index = 0;
	if (ch > 255)
		return ((void *)str + (ch - 256));
	while (index < nb)
	{
		if (mem_str[index] == ch)
			return ((void *)&mem_str[index]);
		index++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:44:23 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/27 20:08:23 by aoropeza         ###   ########.fr       */
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
		return ((void *)mem_str + (ch - 256));
	while (index < nb)
	{
		if (mem_str[index] == ch)
			return ((void *)&mem_str[index]);
		else
			index++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:43:02 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/20 17:47:58 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nb)
{
	unsigned char		*mem_dest;
	const char			*mem_src;
	size_t				index;

	mem_dest = (unsigned char *)dest;
	mem_src = (const char *)src;
	index = 0;
	while (index < nb)
	{
		mem_dest[index] = mem_src[index];
		index++;
	}
	mem_dest[index] = '\0';
	return (mem_dest);
}

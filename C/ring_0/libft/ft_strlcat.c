/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:42:46 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/20 11:24:38 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	index_dest;
	unsigned int	index_src;

	index_dest = 0;
	index_src = 0;
	while (dest[index_dest])
		index_dest++;
	while (index_dest != size)
		dest[index_dest++] = src[index_src++];
	dest[index_dest] = '\0';
	while (src[index_src])
	{
		index_src++;
		index_dest++;
	}
	return (index_dest);
}

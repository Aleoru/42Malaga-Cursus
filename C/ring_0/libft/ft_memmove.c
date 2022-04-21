/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:19:52 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/20 18:11:39 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t nb)
{
	unsigned char	*str_aux;
	const char		*str_src;
	unsigned char	*str_dest;
	size_t			index;

	index = 0;
	str_src = (const char *)src;
	str_dest = (unsigned char *)dest;
	str_aux = (unsigned char *)str_dest;
	while (index < nb)
	{
		str_aux[index] = str_src[index];
		index++;
	}
	index = 0;
	while (index < nb)
	{
		str_dest[index] = str_aux[index];
		index++;
	}
	str_dest[index] = '\0';
	return (str_dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:20:27 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/21 15:02:59 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	index;

	index = 0;
	while (src[index])
	{
		if (index < size)
			dest[index] = src[index];
		else if (index == size)
			dest[index] = '\0';
		index++;
	}
	while (src[index])
		index++;
	return (index);
}

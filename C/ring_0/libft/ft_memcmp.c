/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:48 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/21 17:24:28 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str_one, const void *str_two, size_t nb)
{
	const char	*mem_one;
	const char	*mem_two;
	size_t		index;

	mem_one = (const char *)str_one;
	mem_two = (const char *)str_two;
	index = 0;
	while (index < nb)
	{
		if (mem_one[index] == mem_two[index])
			index++;
		else if (mem_one[index] < mem_two[index])
			return (mem_one[index] - mem_two[index]);
		else if (mem_one[index] > mem_two[index])
			return (mem_one[index] - mem_two[index]);
	}
	return (mem_one[index] - mem_two[index]);
}

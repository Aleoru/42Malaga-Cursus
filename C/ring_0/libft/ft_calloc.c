/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:39:24 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/21 17:00:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*empty;

	if (nitems == 0 || size == 0)
		return (NULL);
	else
	{
		empty = malloc(nitems * size);
		ft_bzero(empty, nitems * size);
		return (empty);
	}
}

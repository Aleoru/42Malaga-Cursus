/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:25:53 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/21 15:00:47 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	index;

	index = ft_strlen((char *)str);
	while (index >= 0)
	{
		if (str[index] == ch)
			return ((char *)&str[index]);
		else
			index--;
	}
	return (0);
}

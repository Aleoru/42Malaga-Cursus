/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:25:53 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/27 20:20:43 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	index;

	index = ft_strlen((char *)str);
	if (ch > 255)
		ch -= 256;
	while (index >= 0)
	{
		if (str[index] == ch)
			return ((char *)&str[index]);
		else
			index--;
	}
	return (NULL);
}

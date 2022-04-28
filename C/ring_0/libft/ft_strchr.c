/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:14:23 by aoropeza          #+#    #+#             */
/*   Updated: 2022/04/27 20:26:01 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	index;

	index = 0;
	if (ch > 255)
		ch -= 256;
	if (ch == 0)
		return ((char *)str + ft_strlen(str));
	while (str[index])
	{
		if (str[index] == ch)
			return ((char *)&str[index]);
		else
			index++;
	}
	return (0);
}

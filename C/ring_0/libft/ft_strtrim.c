/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:42:53 by aoropeza          #+#    #+#             */
/*   Updated: 2022/05/03 18:02:56 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trimlen(char const *s1, char const *set)
{
	size_t	len;
	size_t	index_str;
	size_t	index_set;

	len = ft_strlen(s1);
	index_str = 0;
	index_set = 0;
	while (s1[index_str])
	{
		index_set = 0;
		while (set[index_set])
		{
			if (s1[index_str] == set[index_set++])
				len--;
		}
		index_str++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*aux;
	size_t		index_str;
	size_t		index_set;
	size_t		len;

	if (set[0] == '\0')
		return (ft_strdup(s1));
	len = trimlen(s1, set);
	aux = (char *)malloc(len * (sizeof(char)));
	index_str = 0;
	len = 0;
	while (s1[index_str])
	{
		index_set = 0;
		while (set[index_set] && set[index_set] != s1[index_str])
		{
			if (set[index_set + 1] == '\0')
				aux[len++] = s1[index_str];
			index_set++;
		}
		index_str++;
	}
	aux[len] = '\0';
	return (aux);
}

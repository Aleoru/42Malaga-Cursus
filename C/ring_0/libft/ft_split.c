/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:47:39 by aoropeza          #+#    #+#             */
/*   Updated: 2022/05/10 18:14:31 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_free(char **array)
{
	size_t	elem;

	elem = 0;
	while (array)
	{
		free(array[elem]);
		elem++;
	}
	return (array);
}

static size_t	count_word(char const *str, char c)
{
	size_t	index;
	size_t	elem;
	int		same;

	elem = 0;
	index = 0;
	same = 0;
	while (str[index++])
	{
		if (str[index] != c && str[index - 1] == c && str[index] != '\0')
			elem++;
		if (str[index] != c && str[index] != '\0')
			same = 1;
	}
	if (elem == 0 && same == 1)
	{		
		if (!ft_strchr(str, c) || ft_strrchr(str, c))
			elem++;
	}
	if (elem > 1 && str[0] != c && str[ft_strlen(str)] != c)
		elem++;
	return (elem);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	size_t	elem;
	size_t	str_pos;
	size_t	start;

	if (str == NULL)
		return (NULL);
	array = malloc((count_word(str, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	str_pos = 0;
	elem = 0;
	while (str[str_pos] && elem < count_word(str, c))
	{
		while (str[str_pos] == c && str[str_pos] != '\0')
			str_pos++;
		start = str_pos;
		while (str[str_pos] != c && str[str_pos] != '\0')
			str_pos++;
		array[elem++] = ft_substr(str, start, (str_pos - start));
		if (!array)
			return (split_free(array));
	}
	array[elem] = 0;
	return (array);
}

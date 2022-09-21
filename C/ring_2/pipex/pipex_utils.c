/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:48:12 by aoropeza          #+#    #+#             */
/*   Updated: 2022/09/21 16:48:13 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	index_one;
	unsigned int	index_two;

	index_one = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[index_one] && index_one < len)
	{
		index_two = 0;
		while (str[index_one + index_two] != '\0' && str[index_one + index_two]
			== to_find[index_two] && index_one + index_two < len)
		{
			if (to_find[index_two + 1] == '\0')
				return ((char *)&str[index_one]);
			index_two++;
		}
		index_one++;
	}
	return (0);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_one;
	size_t	len_two;
	size_t	index;

	len_one = ft_strlen(s1);
	len_two = ft_strlen(s2);
	str = (char *)malloc((len_one + len_two + 1));
	index = 0;
	if (str == NULL)
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		str[len_one + index] = s2[index];
		index++;
	}
	str[len_one + len_two] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(const char *str)
{
	char	*cstr;
	int		size;
	int		index;
	char	*p;

	index = 0;
	size = ft_strlen((char *)str);
	cstr = malloc((size + 1) * sizeof(char));
	if (cstr == NULL)
		return (NULL);
	p = cstr;
	while (str[index])
	{
		p[index] = str[index];
		index++;
	}
	p[index] = '\0';
	return (cstr);
}

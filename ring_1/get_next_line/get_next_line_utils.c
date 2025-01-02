/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:59:36 by aoropeza          #+#    #+#             */
/*   Updated: 2022/06/28 14:36:38 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *str, int ch)
{
	int	index;

	index = 0;
	while (str[index] != (char)ch)
	{
		if (!str[index])
			return (0);
		index++;
	}
	return ((char *)&str[index]);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index;

	index = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start] && index < len)
	{
		str[index] = s[start];
		start++;
		index++;
	}
	str[index] = '\0';
	return (str);
}

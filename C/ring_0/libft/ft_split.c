/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:47:39 by aoropeza          #+#    #+#             */
/*   Updated: 2022/05/04 20:45:10 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**word_split(char const *str, char c, size_t n_elem)
{
	size_t	str_pos;
	size_t	start;
	size_t	elem;
	char	**array;

	str_pos = 0;
	elem = 0;
	array = (char **)malloc((n_elem + 1) * (sizeof(char *)));
	if (!array)
		return (NULL);
	while (str[str_pos] && elem < n_elem)
	{
		while (str[str_pos] == c && str[str_pos] != '\0')
			str_pos++;
		start = str_pos;
		while (str[str_pos] != c && str[str_pos] != '\0')
			str_pos++;
		array[elem++] = ft_substr(str, start, (str_pos - start));
	}
	array[elem] = 0;
	return (array);
}

char	**ft_split(char const *str, char c)
{
	size_t	index;
	size_t	elem;
	int		same;

	if (str == 0)
		return (NULL);
	elem = 0;
	index = 0;
	same = 0;
	while (str[index])
	{
		if (str[index] != c && str[index - 1] == c)
			elem++;
		if (str[index] != c)
			same = 1;
		index++;
	}
	if (elem == 0 && same == 1)
	{		
		if (!ft_strchr(str, c))
			elem++;
		else if (ft_strrchr(str, c))
			elem++;
	}
	return (word_split(str, c, elem));
}

/*#include <stdio.h>   

int	main(void)
{
	char	*str = "  tripouille 42  ";
	char	**split;
	//int		index = 0;

	split = ft_split(str, ' ');
	printf("%s\n", split[0]);
	printf("%s\n", split[1]);
	return (0);
}*/

// substr, strlen, strdup

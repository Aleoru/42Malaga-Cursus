/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:33:30 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/04 13:33:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(char const *str, char c)
{
	size_t	index;
	size_t	elem;

	index = 0;
	elem = 0;
	while (str[index] == c)
		index++;
	while (str[index])
	{
		if (str[index] == c && str[index + 1] != c && str[index + 1] != '\0')
			elem++;
		index++;
	}
	return (elem + 1);
}

void	check_argv(char	**argv, t_data *data)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		check = 0;
		while (argv[i][++j])
		{
			if (ft_isalpha(argv[i][j]))
				exit_error(data, 2);
			else if (argv[i][j] == ' ')
				check = 1;
		}			
		if (check == 1)
			data->len_a += count(argv[i], ' ');
		else if (check == 0 && argv[i] != NULL)
			data->len_a++;
	}
}

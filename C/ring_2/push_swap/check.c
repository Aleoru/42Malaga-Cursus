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

void    check_arg(char **argv, t_data *data)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isalpha(argv[i][j]) && argv[i][j] != '\0')
			{
				array = ft_split (argv[i], argv[i][j]);
				break ;
			}
			j++;
		}
		if (argv[i][j] == '\0')
			i++;
	}
}

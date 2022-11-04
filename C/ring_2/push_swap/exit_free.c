/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:03:18 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/04 13:03:22 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_data *data)
{
	write(2, "Error\n", 6);
	/* FREE */
	exit(1);
}

void	free_num(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_a)
	{
		free(&data->stack_a[i]);
		i++;
	}
}

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

void	exit_error(t_data *data, int error)
{
	write(2, "Error\n", 6);
	if (error == 2)
	{
		write(2, "Letters are not numbers.\n", 25);
		exit(1);
	}
	if (error == 3)
		write(2, "Values above int are not allowed.\n", 34);
	if (error == 4)
		write(2, "There are duplicated values.\n", 29);
	free_stack(data);
	exit(1);
}

void	free_stack(t_data *data)
{
	int	i;

	i = data->len_a -1;
	while (i >= data->len_a)
	{
		free(&data->stack_a[i]);
		i--;
	}
}

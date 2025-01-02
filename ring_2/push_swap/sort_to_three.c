/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:56:07 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/04 12:56:13 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	the_greatest(t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < 3)
	{
		if (data->stack_a[0].index > data->stack_a[i + 1].index)
			i++;
		else if (i == 1)
			return (2);
		else if (i == 0)
			return (1);
	}
	return (0);
}

void	sort_three(t_data *data)
{
	if (data->len_a == 1 && is_sorted(data))
		free_stack(data);
	else if (data->len_a == 2)
	{
		if (!is_sorted(data))
			swap(data, A);
	}
	else if (data->len_a == 3)
	{
		while (!is_sorted(data))
		{
			if (the_greatest(data) == 0)
				rotate(data, A);
			else if (the_greatest(data) == 1)
				rev_rotate(data, A);
			else if (the_greatest(data) == 2)
				swap(data, A);
		}
	}
}

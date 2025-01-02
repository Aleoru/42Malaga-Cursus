/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:39:38 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/07 11:39:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	int	i;

	i = 0;
	data->mean = data->len_a / 2;
	while (i < data->len_a && data->len_a > 3)
	{
		if (data->stack_a[0].index < data->mean)
			push(data, B);
		else
		{
			rotate(data, A);
			i++;
		}
	}
	while (data->len_a > 3)
		push(data, B);
	if (!is_sorted(data))
		sort_three(data);
}

static int	minor_value(t_data *data)
{
	int	i;
	int	minor;

	i = 0;
	minor = data->stack_a[0].index;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index < minor)
			minor = data->stack_a[i].index;
		i++;
	}
	return (minor);
}

void	find_partner(t_data *data)
{
	int		i;
	int		j;
	int		major;

	i = 0;
	while (i < data->len_b)
	{
		if (is_greater(data, data->stack_b[i].index))
			data->stack_b[i].partner = minor_value(data);
		else
		{
			major = greater_to(data);
			j = 0;
			while (j < data->len_a)
			{
				if (data->stack_a[j].index < major
					&& data->stack_b[i].index < data->stack_a[j].index)
					major = data->stack_a[j].index;
				j++;
			}
			data->stack_b[i].partner = major;
		}
		movement_cost(data, i);
		i++;
	}
}

void	final_rotation(t_data *data)
{
	int	i;

	i = 0;
	while (data->stack_a[i].index != 0)
		i++;
	if (i > data->mean)
		rev_rotate(data, A);
	else if (i <= data->mean)
		rotate(data, A);
	if (data->stack_a[0].index != 0)
		final_rotation(data);
}

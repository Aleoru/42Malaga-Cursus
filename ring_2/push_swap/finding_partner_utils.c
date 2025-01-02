/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_partner_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:33:36 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/07 12:33:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_greater(t_data *data, int index)
{
	int		i;

	i = 0;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index > index)
			return (0);
		i++;
	}
	return (1);
}

int	greater_to(t_data *data)
{
	int	major;
	int	i;

	i = 0;
	major = data->stack_a[0].index;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index > major)
			major = data->stack_a[i].index;
		i++;
	}
	return (major);
}

static void	calculate_cost(t_data *data, int i, int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			data->stack_b[i].total_cost = cost_a;
		else
			data->stack_b[i].total_cost = cost_b;
	}
	else if (cost_a <= 0 && cost_b <= 0)
	{
		if (cost_a > cost_b)
			data->stack_b[i].total_cost = cost_b * -1;
		else
			data->stack_b[i].total_cost = cost_a * -1;
	}
	else
	{
		if (cost_a < 0)
			data->stack_b[i].total_cost = (cost_a * -1) + cost_b;
		else if (cost_b < 0)
			data->stack_b[i].total_cost = (cost_b * -1) + cost_a;
	}
}

static int	pos_index(t_data *data, char array, int index)
{
	int	pos;

	pos = 0;
	if (array == 'a')
	{
		while (pos < data->len_a)
		{
			if (data->stack_a[pos].index == index)
				return (pos);
			pos++;
		}
	}
	else
	{
		while (pos < data->len_b)
		{
			if (data->stack_b[pos].index == index)
				return (pos);
			pos++;
		}
	}
	return (-1);
}

void	movement_cost(t_data *data, int i)
{
	int	cost_a;
	int	cost_b;

	data->stack_b[i].pos_a = pos_index(data, 'a', data->stack_b[i].partner);
	data->stack_b[i].pos_b = pos_index(data, 'b', data->stack_b[i].index);
	if (data->stack_b[i].pos_a > data->len_a - data->stack_b[i].pos_a)
		data->stack_b[i].cost_a = (data->len_a - data->stack_b[i].pos_a) * -1;
	else
		data->stack_b[i].cost_a = data->stack_b[i].pos_a;
	if (data->stack_b[i].pos_b > data->len_b - data->stack_b[i].pos_b)
		data->stack_b[i].cost_b = (data->len_b - data->stack_b[i].pos_b) * -1;
	else
		data->stack_b[i].cost_b = data->stack_b[i].pos_b;
	cost_a = data->stack_b[i].cost_a;
	cost_b = data->stack_b[i].cost_b;
	calculate_cost(data, i, cost_a, cost_b);
}

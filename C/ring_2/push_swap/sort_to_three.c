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
	while(i + 1 < 3)
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
	{
		free_stack(data);
		exit(EXIT_SUCCESS);
	}
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
	free_stack(data);
	exit(EXIT_SUCCESS);
}

void	sort(t_data *data)
{
	int	i;

	i = 0;
	data->mean = data->len_a / 2;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index < data->mean)
			push(data, B);
		else
		{
			rotate(data, A);
			i++;
		}
	}
	while (data->len_a > 3)
		push(data, B);
	i = -1;
	ft_printf("A	B\n");
	while (++i < data->len_a)
		ft_printf("%d : %d	%d : %d\n", data->stack_a[i].index, data->stack_a[i].value, data->stack_b[i].index, data->stack_b[i].value);
	while (++i < data->len_b)
		ft_printf("	%d : %d\n", data->stack_b[i].index, data->stack_b[i].value);
}
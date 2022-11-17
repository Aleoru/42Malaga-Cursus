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

// static void	only_three(t_data *data);

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
		free_stack(data);
		exit(EXIT_SUCCESS);
	}
	else if (data->len_a == 3)
	{
		while (is_sorted(data) == 0)
		{
			if (data->stack_a[0].index < data->stack_a[1].index)
				swap(data, A);
			else if (data->stack_a[0].index > data->stack_a[1].index)
				rotate(data, A);
		}
		free_stack(data);
		exit(EXIT_SUCCESS);
	}
}
// 2 3 1 | 1 3 2 || 3 2 1 | 3 1 2 | 2 1 3 
			/*ft_printf("%d: %d\n", data->stack_a[0].index, data->stack_a[0].value);
			ft_printf("%d: %d\n", data->stack_a[1].index, data->stack_a[1].value);
			ft_printf("%d: %d\n", data->stack_a[2].index, data->stack_a[2].value);*/

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

void	sort_three(t_data *data)
{
	if (data->len_a == 1)
		is_sorted(data);
	else if (data->len_a == 2)
	{
		swap(data, A);
		is_sorted(data);
	}
	else if (data->len_a == 3)
	{
		if (data->stack_a[0] < data.stack_a[1])
		{
			rotate(data, A);
			swap(data, A);
		}
		is_sorted(data);
	}
}

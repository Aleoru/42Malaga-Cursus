/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_funs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:45:15 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/04 11:45:17 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *data, char c)
{
	t_stack	aux;

	if (c == A || c == RR)
	{
		aux = data->stack_a[0];
		move_up(data->stack_a);
		data->stack_a[data->len_a - 1] = aux;
	}
	if (c == B || c == RR)
	{
		aux = data->stack_b[0];
		move_up(data->stack_b);
		data->stack_b[data->len_b - 1] = aux;
	}
	ft_printf("r%c\n", c);
}

void	rev_rotate(t_data *data, char c)
{
	t_stack	aux;

	if (c == A || c == RR)
	{
		aux = data->stack_a[data->len_a - 1];
		move_down(data->stack_a, data->len_a);
		data->stack_a[0] = aux;
	}
	if (c == B || c == RR)
	{
		aux = data->stack_b[data->len_b - 1];
		move_down(data->stack_b, data->len_b);
		data->stack_b[0] = aux;
	}
	ft_printf("rr%c\n", c);
}

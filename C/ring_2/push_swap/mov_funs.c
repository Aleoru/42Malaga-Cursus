/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_funs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:12:16 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/02 12:12:32 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	move_up(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack[i].value)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	move_down(t_stack *stack, int len)
{
	while (len >= 0)
	{
		stack[len + 1] = stack[len];
		len--;
	}
}

void	swap(t_data *data, char c)
{
	t_stack	aux;

	if (c == A || c == SS)
	{
		if (data->len_a < 2)
			return ;
		aux = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = aux;
	}
	if (c == B || c == SS)
	{
		if (data->len_b < 2)
			return ;
		aux = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = aux;
	}
	ft_printf("s%c\n", c);
}

void	push(t_data *data, char c)
{
	if (c == A)
	{
		if (!data->stack_b)
			return ;
		if (data->stack_a)
			move_down(data->stack_a, data->len_a);
		data->stack_a[0] = data->stack_b[0];
		data->len_a++;
		move_up(data->stack_b);
		data->len_b--;
	}
	if (c == B)
	{
		if (!data->stack_a)
			return ;
		if (data->stack_b)
			move_down(data->stack_b, data->len_b);
		data->stack_b[0] = data->stack_a[0];
		data->len_b++;
		move_up(data->stack_a);
		data->len_a--;
	}
	ft_printf("p%c\n", c);
}

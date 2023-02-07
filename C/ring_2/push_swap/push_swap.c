/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:28:56 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/02 11:28:58 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	stack_size(int *stack)
{
	int	size;

	size = 0;
	while (stack[size])
		size++;
	return (size);
}

static void	sort_stack(t_data *data, t_stack *stack)
{
	int		i;
	int		j;
	t_stack	aux;

	i = -1;
	while (++i < data->len_a)
	{
		aux = stack[i];
		j = i;
		while (++j < data->len_a)
		{
			if (aux.value > stack[j].value)
			{	
				aux = stack[j];
				stack[j] = stack[i];
				stack[i] = aux;
			}
		}
	}
	while (--i >= 0)
	{
		stack[i].index = i;
		if ((stack[i].value == stack[i + 1].value) && (i + 1 < data->len_a))
			exit_error(data, 4);
	}
}

static void	value_index(t_data *data)
{
	t_stack	*stack;
	int		i;
	int		j;

	stack = malloc(data->len_a * sizeof(t_stack));
	i = -1;
	while (++i < data->len_a)
		stack[i] = data->stack_a[i];
	sort_stack(data, stack);
	i = -1;
	while (++i < data->len_a)
	{
		j = -1;
		while (++j < data->len_a)
		{
			if (data->stack_a[i].value == stack[j].value)
			{
				data->stack_a[i].index = stack[j].index;
				j = -1;
				break ;
			}
		}
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		ft_bzero(&data, sizeof(t_data));
		check_argv(argv, &data);
		stack_argv(argv, &data);
		value_index(&data);
		if (!is_sorted(&data) && data.len_a <= 3)
			sort_three(&data);
		else if (!is_sorted(&data))
			sort(&data);
		while (data.len_b != 0)
		{
			find_partner(&data);
			final_sort(&data);
		}
		final_rotation(&data);
		free_stack(&data);
	}
	else
		exit_error(&data, 2);
	return (0);
}

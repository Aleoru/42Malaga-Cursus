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
	t_stack	check;

	i = 0;
	while (++i < data->len_a)
	{
		j = -1;
		check = stack[i];
		while (++j < data->len_a)
		{
			if (check.value < stack[j].value)
			{	
				aux = stack[j];
				stack[j] = check;
				stack[i] = aux;
				check = stack[i];
				j = -1;
			}
		}
	}
	i = -1;
	while (++i < data->len_a)
		stack[i].index = i;
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
		is_sorted(&data);
	}
	else
		ft_printf("Faltan argumentos\n");
	return (0);
}

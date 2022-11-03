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

void	value_index(t_data *data)
{
	t_stack	*stack;
	t_stack	aux;
	t_stack	check;
	int		i;
	int		j;

	i = 0;
	stack = malloc(data->len_a * sizeof(t_stack));
	while (i < data->len_a)
	{
		stack[i] = data->stack_a[i];
		i++;
	}
	i = 0;
	while (i < data->len_a)
	{
		j = 0;
		check = stack[i];
		while (j < data->len_a)
		{
			if (check.value < stack[j].value)
			{	
				aux = stack[j];
				stack[j] = check;
				stack[i] = aux;
				check = stack[i];
				j = 0;
			}
			else
				j++;
		}
		i++;
	}
	i = -1;
	while (++i < data->len_a)
		ft_printf("%d, ", stack[i].value);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 1;
	ft_bzero(&data, sizeof(t_data));
	data.len_a = 0;
	if (argc > 1)
	{
		data.stack_a = malloc(argc * sizeof(t_stack));
		data.stack_b = malloc(argc * sizeof(t_stack));
		while (argv[i])
		{
			data.stack_a[data.len_a].value = ft_atoi(argv[i]);
			// ft_printf("%d\n", data.stack_a[i - 1].value);
			data.stack_a[data.len_a].index = data.len_a;
			i++;
			data.len_a++;
		}
		value_index(&data);
		i = -1;
	}
	else
		ft_printf("Faltan argumentos\n");
	return (0);
}

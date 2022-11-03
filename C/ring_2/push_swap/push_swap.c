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
		// ft_printf("Tamaño stack: %d\n", data.len_a);
		push(&data, B);
		ft_printf("0: %d\n", data.stack_a[0].value);
		ft_printf("Ultimo: %d\n",data.stack_b[0].value);
	}
	else
		ft_printf("Faltan argumentos\n");
	return (0);
}

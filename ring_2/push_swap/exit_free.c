/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:03:18 by aoropeza          #+#    #+#             */
/*   Updated: 2022/11/04 13:03:22 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_data *data, int error)
{
	write(2, "Error\n", 6);
	if (error == 2)
		exit(1);
	free(data->stack_a);
	free(data->stack_b);
	exit(1);
}

void	free_stack(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
	exit(EXIT_SUCCESS);
}

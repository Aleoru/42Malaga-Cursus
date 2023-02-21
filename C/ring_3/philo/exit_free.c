/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:51:44 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 19:51:46 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error(t_table *table, int error)
{
	write(2, "Error\n", 6);
	if (error > 2)
		free(table->philo);
	printf("%d\n", error);
	return (error);
}

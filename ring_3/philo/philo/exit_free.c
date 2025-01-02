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
	return (error);
}

void	clear_the_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (table->forks[i].free == 0)
			pthread_mutex_unlock(&table->forks[i].m_fork);
		pthread_mutex_destroy(&table->forks[i].m_fork);
		i++;
	}
	pthread_mutex_destroy(&table->m_philo);
	free(table->forks);
	free(table->philo);
}

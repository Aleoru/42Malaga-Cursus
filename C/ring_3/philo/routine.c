/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:05:49 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/22 13:05:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_state(t_table *table)
{
	int		pos;
	time_t	time;

	pos = table->pos;
	time = get_time_in_ms();
	if (table->philo[pos].state == THINK
		&& time == table->philo[pos].t_next_state)
		table->philo[pos].state = HUNGRY;
	else if (table->philo[pos].state == HUNGRY
		&& time == table->philo[pos].t_next_state)
	{
		table->philo[pos].state = EATING;
		table->philo[pos].t_next_state = get_time_in_ms() + table->t_eat;
		table->philo[pos].t_die = get_time_in_ms() + table->t_die;
	}
	else if (table->philo[pos].state == EATING
		&& time == table->philo[pos].t_next_state)
	{
		table->philo[pos].state = SLEEP;
		table->philo[pos].t_next_state = get_time_in_ms() + table->t_sleep;
	}
	else if (table->philo[pos].state == SLEEP
		&& time == table->philo[pos].t_next_state)
	{
		table->philo[pos].state = THINK;
		table->philo[pos].t_next_state = get_time_in_ms() + 20;
	}
}

void	*routine(void *data)
{
	t_table	*table;
	int		pos;
	time_t	time;

	table = (t_table *)data;
	pos = table->pos;
	table->pos++;
	while (table->end)
	{
		usleep(100000);
		check_state(table);
		time = time_from_start(table);
		printf("%ld	->%d: %d\n", time, table->philo[pos].name, table->philo[pos].state);
	}
	return (NULL);
}

void	call_philos(t_table *table)
{
	int	pos;

	pos = 0;
	while (pos < table->num_philo)
	{
		table->pos = pos;
		pthread_create(table->philo[pos].philo, NULL, routine, &table);
	}
}

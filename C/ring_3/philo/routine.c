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

static void	check_state(t_table *table, int pos)
{
	time_t	time;

	time = get_time_in_ms();
	printf("0\n");
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
	pthread_mutex_unlock(&table->m_philo);
	table->philo[pos].t_next_state = get_time_in_ms();
	table->philo[pos].t_die = get_time_in_ms() + table->t_die;
	while (table->end)
	{
		usleep(100000);
		time = time_from_start(table);
		printf("%ld	->%d: %d\n", time, table->philo[pos].name, table->philo[pos].state);
		check_state(table, pos);
	}
	return (NULL);
}

void	call_philos(t_table *table)
{
	int	pos;

	table->pos = 0;
	pthread_mutex_init(&table->m_philo, NULL);
	while (pos < table->num_philo)
	{
		pos = table->pos;
		pthread_mutex_lock(&table->m_philo);
		pthread_create(&table->philo[pos].th_philo, NULL, routine, &table);
	}
}

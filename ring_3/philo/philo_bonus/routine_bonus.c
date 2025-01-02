/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:05:49 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/22 13:05:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_state(t_table *table)
{
	time_t	time;

	time = time_from_start(table);
	if (table->philo.state == HUNGRY)
		printf("%ld %d has taken a fork\n", time, table->philo.name);
	else if (table->philo.state == EATING)
		printf("%ld %d is eating\n", time, table->philo.name);
	else if (table->philo.state == SLEEP)
		printf("%ld %d is sleeping\n", time, table->philo.name);
	else if (table->philo.state == THINK)
		printf("%ld %d is thinking\n", time, table->philo.name);
	else if (table->philo.state == DEAD)
		printf("%ld %d died\n", time, table->philo.name);
}

static void	next_state(t_table *table)
{
	time_t	time;

	time = get_time_in_ms();
	if (table->philo.state == THINK
		&& time >= table->philo.t_next_state)
		table->philo.state = HUNGRY;
	else if (table->philo.state == HUNGRY
		&& time >= table->philo.t_next_state)
	{
		sem_wait(table->sem_fork);
		eating(table);
	}
	else if (table->philo.state == EATING
		&& time >= table->philo.t_next_state)
		release_forks(table);
	else if (table->philo.state == SLEEP
		&& time >= table->philo.t_next_state)
	{
		table->philo.state = THINK;
		table->philo.t_next_state = get_time_in_ms();
		print_state(table);
	}
}

void	check_state(t_table *table)
{
	time_t	time;

	time = get_time_in_ms();
	if (table->philo.state == SLEEP && table->f_meals > 0
		&& table->philo.meals == table->f_meals)
	{
		sem_post(table->sem_fork);
		table->end = 0;
		exit(EXIT_FULL);
		return ;
	}
	if (time >= table->philo.t_next_state)
		next_state(table);
}

void	*routine(void *data)
{
	t_table	*table;
	time_t	time;

	table = (t_table *)data;
	while (table->end)
	{
		usleep(1000);
		time = get_time_in_ms();
		if (time >= table->philo.t_die)
		{
			table->philo.state = DEAD;
			print_state(table);
			table->end = 0;
			exit(EXIT_DEAD);
		}
	}
	return (NULL);
}

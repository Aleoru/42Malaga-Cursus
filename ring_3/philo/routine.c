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

void	print_state(t_table *table, int pos)
{
	time_t	time;

	time = time_from_start(table);
	if (table->philo[pos].state == HUNGRY)
		printf("%ld %d has taken a fork\n", time, table->philo[pos].name);
	else if (table->philo[pos].state == EATING)
		printf("%ld %d is eating\n", time, table->philo[pos].name);
	else if (table->philo[pos].state == SLEEP)
		printf("%ld %d is sleeping\n", time, table->philo[pos].name);
	else if (table->philo[pos].state == THINK)
		printf("%ld %d is thinking\n", time, table->philo[pos].name);
	else if (table->philo[pos].state == DEAD)
		printf("%ld %d died\n", time, table->philo[pos].name);
}

static void	pick_up_forks(t_table *table, int pos, char handed)
{
	int	fork;

	fork = -1;
	if (handed == LEFT_H && table->philo[pos].picked == 0)
		fork = table->philo[pos].fork_l;
	else if (handed == RIGHT_H && table->philo[pos].picked == 0)
		fork = table->philo[pos].fork_r;
	else if (handed == LEFT_H && table->philo[pos].picked == 1)
		fork = table->philo[pos].fork_r;
	else if (handed == RIGHT_H && table->philo[pos].picked == 1)
		fork = table->philo[pos].fork_l;
	if (fork < 0)
		return ;
	if (table->forks[fork].free == 1)
	{
		pthread_mutex_lock(&table->forks[fork].m_fork);
		table->forks[fork].free = 0;
		table->philo[pos].picked++;
		print_state(table, pos);
		//printf("PHILO: %d, FORK: %d\n", table->philo[pos].name, table->forks[fork].pos);
	}
	if (table->philo[pos].picked == 2)
	{
		table->philo[pos].state = EATING;
		table->philo[pos].t_die = get_time_in_ms() + table->t_die;
		table->philo[pos].t_next_state = get_time_in_ms() + table->t_eat;
		table->philo[pos].meals++;
		print_state(table, pos);
	}
}

static void	release_forks(t_table *table, int pos)
{
	int	fork_l;
	int	fork_r;

	fork_l = table->philo[pos].fork_l;
	fork_r = table->philo[pos].fork_r;
	pthread_mutex_unlock(&table->forks[fork_l].m_fork);
	table->forks[fork_l].free = 1;
	pthread_mutex_unlock(&table->forks[fork_r].m_fork);
	table->forks[fork_r].free = 1;
	table->philo[pos].picked = 0;
	table->philo[pos].state = SLEEP;
}

static void	next_state(t_table *table, int pos)
{
	time_t	time;

	time = get_time_in_ms();
	if (table->philo[pos].state == THINK
		&& time >= table->philo[pos].t_next_state)
		table->philo[pos].state = HUNGRY;
	else if (table->philo[pos].state == HUNGRY
		&& time >= table->philo[pos].t_next_state)
	{
		if (pos % 2 == 0)
			pick_up_forks(table, pos, RIGHT_H);
		else
			pick_up_forks(table, pos, LEFT_H);
	}
	else if (table->philo[pos].state == EATING
		&& time >= table->philo[pos].t_next_state)
	{
		release_forks(table, pos);
		table->philo[pos].t_next_state = get_time_in_ms() + table->t_sleep;
		print_state(table, pos);
	}
	else if (table->philo[pos].state == SLEEP
		&& time >= table->philo[pos].t_next_state)
	{
		table->philo[pos].state = THINK;
		table->philo[pos].t_next_state = get_time_in_ms();
		print_state(table, pos);
	}
}

static void	check_state(t_table *table, int pos)
{
	time_t	time;

	time = get_time_in_ms();
	if (time >= table->philo[pos].t_die)
	{
		table->philo[pos].state = DEAD;
		print_state(table, pos);
		table->end = 0;
		return ;
	}
	else if (check_deaths(table) || (table->f_meals > 0 && check_meals(table)))
	{
		table->end = 0;
		return ;
	}
	else if (time >= table->philo[pos].t_next_state)
		next_state(table, pos);
}

void	*routine(void *data)
{
	t_table	*table;
	int		pos;

	table = (t_table *)data;
	pos = table->pos;
	table->pos++;
	pthread_mutex_unlock(&table->m_philo);
	if (pos % 2 != 0)
		table->philo[pos].state = HUNGRY;
	table->philo[pos].t_next_state = get_time_in_ms();
	table->philo[pos].t_die = get_time_in_ms() + table->t_die;
	print_state(table, pos);
	while (table->end)
	{
		usleep(500);
		check_state(table, pos);
	}
	return (NULL);
}

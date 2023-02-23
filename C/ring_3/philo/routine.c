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

static void	print_state(t_table *table, int pos)
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

static void	pick_up_forks(t_table *table, int pos)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (table->forks[i].pos == table->philo[pos].fork_r
			|| table->forks[i].pos == table->philo[pos].fork_l)
		{
			pthread_mutex_lock(&table->forks[i].m_fork);
			table->forks[i].free = 0;
			table->philo[pos].picked++;
			print_state(table, pos);
		}
		i++;
	}
	if (table->philo[pos].picked == 2)
	{
		table->philo[pos].state = EATING;
		table->philo[pos].t_die = get_time_in_ms() + table->t_die;
		table->philo[pos].t_next_state = get_time_in_ms() + table->t_eat;
		table->philo[pos].meals++;
	}
}

static void	next_state(t_table *table, int pos)
{
	time_t	time;

	time = get_time_in_ms();
	if (table->philo[pos].state == THINK
		&& time >= table->philo[pos].t_next_state)
	{
		table->philo[pos].state = HUNGRY;
		table->philo[pos].t_next_state = get_time_in_ms();
	}
	else if (table->philo[pos].state == HUNGRY
		&& time >= table->philo[pos].t_next_state)
	{
		// Comprobar si hay tenedores libres
		pick_up_forks(table, pos);
	}
	else if (table->philo[pos].state == EATING
		&& time >= table->philo[pos].t_next_state)
	{
		// Crear función para liberar tenedores
		table->philo[pos].state = SLEEP;
		table->philo[pos].t_next_state = get_time_in_ms() + table->t_sleep;
		print_state(table, pos);
	}
	else if (table->philo[pos].state == SLEEP
		&& time >= table->philo[pos].t_next_state)
	{
		table->philo[pos].state = THINK;
		table->philo[pos].t_next_state = get_time_in_ms() + 20;
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
	else if (table->f_meals > 0 && table->philo[pos].meals == table->f_meals)	// Crear función que compruebe
	{																			// si todos los filos han comido
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
	table->philo[pos].t_next_state = get_time_in_ms();
	table->philo[pos].t_die = get_time_in_ms() + table->t_die;
	while (table->end)
	{
		usleep(500);
		check_state(table, pos);
	}
	return (NULL);
}

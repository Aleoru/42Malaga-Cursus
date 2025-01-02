/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:50:59 by aoropeza          #+#    #+#             */
/*   Updated: 2023/03/06 17:51:01 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_table *table, int pos)
{
	table->philo[pos].state = EATING;
	table->philo[pos].t_die = get_time_in_ms() + table->t_die;
	table->philo[pos].t_next_state = get_time_in_ms() + table->t_eat;
	table->philo[pos].meals++;
	print_state(table, pos);
}

void	pick_up_forks(t_table *table, int pos, char handed)
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
	}
	if (table->philo[pos].picked == 2)
		eating(table, pos);
}

void	release_forks(t_table *table, int pos)
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
	table->philo[pos].t_next_state = get_time_in_ms() + table->t_sleep;
	print_state(table, pos);
}

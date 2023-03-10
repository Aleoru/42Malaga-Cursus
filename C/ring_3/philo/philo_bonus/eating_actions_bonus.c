/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_actions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:50:59 by aoropeza          #+#    #+#             */
/*   Updated: 2023/03/06 17:51:01 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_table *table)
{
	if (table->num_philo == 1 && !table->one_fork)
	{
		print_state(table);
		table->one_fork++;
		return ;
	}
	else if (table->one_fork == 1)
		return ;
	sem_wait(table->sem_write);
	print_state(table);
	print_state(table);
	sem_post(table->sem_write);
	table->philo.state = EATING;
	table->philo.t_die = get_time_in_ms() + table->t_die;
	table->philo.t_next_state = get_time_in_ms() + table->t_eat;
	table->philo.meals++;
	print_state(table);
}

void	release_forks(t_table *table)
{
	sem_post(table->sem_fork);
	table->philo.state = SLEEP;
	table->philo.t_next_state = get_time_in_ms() + table->t_sleep;
	print_state(table);
}

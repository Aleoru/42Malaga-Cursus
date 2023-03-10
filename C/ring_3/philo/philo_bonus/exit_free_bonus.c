/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:51:44 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 19:51:46 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	exit_error(int error)
{
	write(2, "Error\n", 6);
	return (error);
}

void	close_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		kill(table->pid[i], 9);
		i++;
	}
}

void	close_sem(t_table *table)
{
	sem_unlink("/fork");
	sem_unlink("/write");
	sem_close(table->sem_fork);
	sem_close(table->sem_write);
}

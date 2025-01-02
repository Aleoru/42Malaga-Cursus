/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:13:21 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 18:13:26 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	fill_philo(t_table *table, int pos)
{
	table->philo.name = pos + 1;
	table->philo.state = THINK;
	table->philo.meals = 0;
	table->philo.picked = 0;
	table->philo.t_next_state = get_time_in_ms();
	table->philo.t_die = get_time_in_ms() + table->t_die;
	pthread_create(&table->philo.th_philo, NULL, *routine, table);
	print_state(table);
	while (table->end)
	{
		usleep(500);
		check_state(table);
	}
	exit(EXIT_SUCCESS);
}

static void	fill_table(t_table *table, char	**argv, int argc)
{
	int	i;

	i = 0;
	table->num_philo = ft_atoli(argv[1]);
	table->t_die = ft_atoli(argv[2]);
	table->t_eat = ft_atoli(argv[3]);
	table->t_sleep = ft_atoli(argv[4]);
	if (argc == 6)
		table->f_meals = ft_atoli(argv[5]);
	table->end = 1;
	table->fork_pairs = table->num_philo / 2;
	table->pid = malloc(table->num_philo * sizeof(pid_t));
	sem_unlink("/fork");
	sem_unlink("/write");
	table->sem_fork = sem_open("/fork", O_CREAT, 0644, table->fork_pairs);
	table->sem_write = sem_open("/write", O_CREAT, 0644, 1);
	table->one_fork = 0;
	table->start = get_time_in_ms();
	while (i < table->num_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] == 0)
			fill_philo(table, i);
		i++;
	}
}

static void	wait_processes(t_table *table)
{
	int	state;
	int	exit;

	waitpid(0, &state, 0);
	exit = WEXITSTATUS(state);
	if (exit == EXIT_DEAD)
		close_processes(table);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (check_argv(argv))
			return (1);
		fill_table(&table, argv, argc);
		if (check_table(&table, argc))
			return (2);
		wait_processes(&table);
	}
	else
		write(2, "Error\n", 6);
	free(table.pid);
	return (0);
}

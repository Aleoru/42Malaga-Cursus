/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:13:21 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 18:13:26 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_table(t_table *table, char	**argv, int argc)
{
	table->num_philo = ft_atoli(argv[1]);
	table->t_die = ft_atoli(argv[2]);
	table->t_eat = ft_atoli(argv[3]);
	table->t_sleep = ft_atoli(argv[4]);
	if (argc == 6)
		table->f_meals = ft_atoli(argv[5]);
	table->end = 1;
}

static void	fill_philo_and_forks(t_table *table)
{
	int	i;

	table->philo = malloc(table->num_philo * sizeof(t_philo));
	table->forks = malloc(table->num_philo * sizeof(t_fork));
	i = 0;
	table->start = get_time_in_ms();
	while (i < table->num_philo)
	{
		table->philo[i].name = i + 1;
		if (i == 0)
			table->philo[i].fork_l = table->num_philo;
		else
			table->philo[i].fork_l = i;
		table->philo[i].fork_r = i + 1;
		table->philo[i].state = THINK;
		table->philo[i].meals = 0;
		table->forks[i].pos = i + 1;
		i++;
	}
}

void	sitting_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->philo[i].th_philo, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (check_argv(&table, argv))
			return (1);
		fill_table(&table, argv, argc);
		if (check_table(&table, argc))
			return (2);
		fill_philo_and_forks(&table);
		call_philos(&table);
		sitting_philo(&table);
	}
	else
		printf("Faltan o sobran argumentos\n");
	return (0);
}

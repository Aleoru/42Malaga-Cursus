/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:50:52 by aoropeza          #+#    #+#             */
/*   Updated: 2023/02/21 19:50:54 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(t_table *table, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (exit_error(table, 1));
		if (ft_atoli(argv[i]) > INT_MAX || ft_atoli(argv[i]) < INT_MIN)
			return (exit_error(table, 1));
	}
	return (0);
}

int	check_table(t_table *table, int argc)
{
	if (table->num_philo < 1)
		return (exit_error(table, 2));
	if (table->t_die < 1)
		return (exit_error(table, 2));
	if (table->t_eat < 1)
		return (exit_error(table, 2));
	if (table->t_sleep < 1)
		return (exit_error(table, 2));
	if (argc == 6)
		if (table->f_meals < 1)
			return (exit_error(table, 2));
	return (0);
}

int	check_meals(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (table->philo[i].meals != table->f_meals)
			return (0);
		i++;
	}
	return (1);
}

int	check_deaths(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (table->philo[i].state == DEAD)
			return (1);
		i++;
	}
	return (0);
}
